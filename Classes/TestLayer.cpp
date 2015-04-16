#include "TestLayer.h"

Scene* TestLayer::scene()
{
    Scene* scene = Scene::create();
    TestLayer* layer = TestLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TestLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    //获取设备尺寸
    auto size = Director::getInstance()->getWinSize();
    
    //背景	
	LdMap* map = LdMap::create();
	Config::getInstance()->setMap(map);
	addChild(map);

    //Sprite* bg = Sprite::create(IMG_BG + String::createWithFormat("img_bg_level_%d.jpg", level)->getCString());
    //bg->setPosition(Vec2(size.width * 0.5, size.height * 0.5));
    //addChild(bg);
	
	//音乐
	if (soundOn)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic((MUSIC + "gameMusic.mp3").c_str(), true);
	}

	//飞机
	Player* player = Player::getInstance();
	player->setType(PlanType::RED);
	auto p_size = player->getContentSize();
	player->setPosition((size.width - p_size.width) / 2, 200);
    addChild(player);

	//暂停
	MenuItemImage* pause = MenuItemImage::create(IMG_MENU + "pause.png", IMG_MENU + "pause.png", CC_CALLBACK_1(TestLayer::doPause, this));
    pause->setAnchorPoint(Vec2(1, 1));
    Menu* menu = Menu::create(pause, NULL);
	menu->setPosition(size.width - 10, size.height - 10);
    addChild(menu);

	//分数
	    
	//敌机
	this->schedule(schedule_selector(TestLayer::addEnemy), 2);

	//触摸
	Vec2 min = Vec2(p_size.width / 2, p_size.height / 2);
	Vec2 max = Vec2(size.width - p_size.width / 2, size.height - p_size.height / 2);
	auto _listener_touch = EventListenerTouchOneByOne::create();
	_listener_touch->onTouchBegan = CC_CALLBACK_2(TestLayer::TouchBegan, this);
	_listener_touch->onTouchMoved = CC_CALLBACK_2(TestLayer::TouchMoved, this, min, max);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener_touch, this);
	
    return true;
}

void TestLayer::addEnemy(float time)
{
	Enemy* enemy = Enemy::createEnemy();	
	auto size = Director::getInstance()->getWinSize();
	auto contentSize = enemy->getContentSize();
	float x = CCRANDOM_0_1() * size.width;
	x = x < contentSize.width / 2 ? contentSize.width / 2 : 
		(x > size.width - contentSize.width / 2 ? size.width - contentSize.width / 2 : x);
	float y = size.height + contentSize.height;
	enemy->setPosition(x, y);
	this->addChild(enemy);
}

bool TestLayer::TouchBegan(Touch *pTouch, Event *pEvent)
{
	return true;
}

void TestLayer::TouchMoved(Touch *pTouch, Event *pEvent, Vec2 min, Vec2 max)
{
	Player* player = Player::getInstance();
	if (!player || player->getDead())
	{
		return;
	}
	Vec2 position = player->getPosition() + pTouch->getDelta();
	position.clamp(min, max);
	player->setPosition(position);
}

void TestLayer::doPause(Ref* psend)
{
	log("doPause");
	Director::getInstance()->pause();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
    PauseLayer* pauseLayer = PauseLayer::create();
    addChild(pauseLayer, 1);
}