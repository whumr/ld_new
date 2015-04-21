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
    //»ñÈ¡Éè±¸³ß´ç
    auto size = Director::getInstance()->getWinSize();
    
    //±³¾°	
	LdMap* map = LdMap::create();
	Config::getInstance()->setMap(map);
	addChild(map);

    //Sprite* bg = Sprite::create(IMG_BG + String::createWithFormat("img_bg_level_%d.jpg", level)->getCString());
    //bg->setPosition(Vec2(size.width * 0.5, size.height * 0.5));
    //addChild(bg);
	
	//ÒôÀÖ
	if (soundOn)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic((MUSIC + "gameMusic.mp3").c_str(), true);
	}

	//·É»ú
	Player* player = Player::getInstance();
	player->setType(PlanType::RED);
	auto p_size = player->getContentSize();
	player->setPosition((size.width - p_size.width) / 2, 200);
    addChild(player);

	//ÔÝÍ£
	MenuItemImage* pause = MenuItemImage::create(IMG_MENU + "pause.png", IMG_MENU + "pause.png", CC_CALLBACK_1(TestLayer::doPause, this));
    pause->setAnchorPoint(Vec2(1, 1));
    Menu* menu = Menu::create(pause, NULL);
	menu->setPosition(size.width - 10, size.height - 10);
    addChild(menu);

	//·ÖÊý
	_score = player->getScore();
	Label* score_label = Label::createWithSystemFont("score", DEFAULT_FONT, 24);
    score_label->setPosition(30, size.height-22);
    addChild(score_label);
    
	Label* labelScores = Label::createWithSystemFont(String::createWithFormat("%d", _score)->getCString(), DEFAULT_FONT, 24);
    labelScores->setPosition(110, size.height-22);
    labelScores->setColor(Color3B(255, 255, 0));
	labelScores->setTag(LayerTag::TAG_SCORE);
    addChild(labelScores);

	//ÏÔÑª
	this->drawHp(true);

	//´óÕÐ
	    
	//µÐ»ú
	this->schedule(schedule_selector(TestLayer::addEnemy), 2);

	//´¥Ãþ
	Vec2 min = Vec2(p_size.width / 2, p_size.height / 2);
	Vec2 max = Vec2(size.width - p_size.width / 2, size.height - p_size.height / 2);
	auto _listener_touch = EventListenerTouchOneByOne::create();
	_listener_touch->onTouchBegan = CC_CALLBACK_2(TestLayer::TouchBegan, this);
	_listener_touch->onTouchMoved = CC_CALLBACK_2(TestLayer::TouchMoved, this, min, max);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener_touch, this);
	
	this->scheduleUpdate();
    return true;
}

void TestLayer::addEnemy(float time)
{
	Enemy* enemy1 = Enemy::createEnemy(EnemyType::LOWEST);		
	this->addChild(enemy1);
	Enemy* enemy = Enemy::createEnemy(EnemyType::LOW);		
	this->addChild(enemy);
	Enemy* enemy2 = Enemy::createEnemy(EnemyType::NORMAL);		
	this->addChild(enemy2);
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

void TestLayer::drawHp(bool init)
{	
	if (init)
	{
		for (int i = 0; i < 3; i ++)
		{
			Sprite* hp = Sprite::createWithSpriteFrameName("player_hp");
			hp->setTag(LayerTag::TAG_HP_1 + i);
			hp->setPosition(25 * (i + 1), hp->getContentSize().height / 2);
			addChild(hp);
		}
		
	}
	int hp = Player::getInstance()->getHp();
	if (hp != _player_hp)
	{
		_player_hp = Player::getInstance()->getHp();
		for (int i = 0; i < 3; i ++)
		{
			if (_player_hp > i)
			{
				getChildByTag(LayerTag::TAG_HP_1 + i)->setVisible(true);
			}
			else
			{
				getChildByTag(LayerTag::TAG_HP_1 + i)->setVisible(false);
			}
		}
	}	
}

void TestLayer::drawScore()
{
	_score = Player::getInstance()->getScore();
	((Label*)getChildByTag(LayerTag::TAG_SCORE))->setString(String::createWithFormat("%d", _score)->getCString());
}

void TestLayer::update(float time)
{
	int hp = Player::getInstance()->getScore();
	if (hp != _player_hp)
	{
		drawHp();
	}
	int score = Player::getInstance()->getScore();
	if (score != _score)
	{
		drawScore();
	}
}