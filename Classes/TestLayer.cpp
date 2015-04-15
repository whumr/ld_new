#include "TestLayer.h"
#include "MenuLayer.h"
#include "Player.h"
#include "Enemy.h"

Scene* TestLayer::scene()
{
    Scene *scene = Scene::create();
    TestLayer *layer = TestLayer::create();
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
    Sprite* bg = Sprite::create(IMG_BG + "img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
        
	//Sprite* s = Sprite::create("enemy_bug.png");
	//s->setPosition(size.width/2, size.height/2);
	//addChild(s);

	Player* player = Player::getInstance();
	player->setType(PlanType::RED);
	auto p_size = player->getContentSize();
	player->setPosition((size.width - p_size.width) / 2, 200);
    addChild(player);

    //添加一个按钮用于返回Menu
	MenuItemImage * back= MenuItemImage::create(IMG_MENU + "backHomeWord.png", IMG_MENU + "backHomeWord.png",CC_CALLBACK_1(TestLayer::backMenu, this));
    Menu* backMenu =Menu::create(back,NULL);
    backMenu->setPosition(Vec2(size.width/2, 30));
    addChild(backMenu);
	    
	this->schedule(schedule_selector(TestLayer::addEnemy), 3);

	Vec2 min = Vec2(p_size.width / 2, p_size.height / 2);
	Vec2 max = Vec2(size.width - p_size.width / 2, size.height - p_size.height / 2);
	auto _listener_touch = EventListenerTouchOneByOne::create();
	_listener_touch->onTouchBegan = CC_CALLBACK_2(TestLayer::TouchBegan, this);
	_listener_touch->onTouchMoved = CC_CALLBACK_2(TestLayer::TouchMoved, this, min, max);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener_touch, this);

    return true;
}

void TestLayer::backMenu(Ref* psend){
    //切换到"菜单"场景
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
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