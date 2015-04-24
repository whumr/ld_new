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
	_player_hp = player->getHp();
	_player_thunder = player->getThunder();

	//暂停
	MenuItemImage* pause = MenuItemImage::create(IMG_MENU + "pause.png", IMG_MENU + "pause.png", CC_CALLBACK_1(TestLayer::doPause, this));
    pause->setAnchorPoint(Vec2(1, 1));
    Menu* menu = Menu::create(pause, NULL);
	menu->setPosition(size.width - 10, size.height - 10);
    addChild(menu);

	//分数
	_score = player->getScore();
	Label* score_label = Label::createWithSystemFont("score", DEFAULT_FONT, 24);
    score_label->setPosition(30, size.height-22);
    addChild(score_label);
    
	Label* labelScores = Label::createWithSystemFont(String::createWithFormat("%d", _score)->getCString(), DEFAULT_FONT, 24);
    labelScores->setPosition(110, size.height-22);
    labelScores->setColor(Color3B(255, 255, 0));
	labelScores->setTag(LayerTag::TAG_SCORE);
    addChild(labelScores);

	//显血
	this->drawHp(true);

	//大招
	this->drawThunder(true);
	    
	//敌机
	this->schedule(schedule_selector(TestLayer::addEnemy), 2);
	
	//道具
	this->schedule(schedule_selector(TestLayer::addGem), 20);

	//触摸
	Vec2 min = Vec2(p_size.width / 2, p_size.height / 2);
	Vec2 max = Vec2(size.width - p_size.width / 2, size.height - p_size.height / 2);
	auto _listener_touch = EventListenerTouchOneByOne::create();
	_listener_touch->onTouchBegan = CC_CALLBACK_2(TestLayer::TouchBegan, this);
	_listener_touch->onTouchMoved = CC_CALLBACK_2(TestLayer::TouchMoved, this, min, max);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener_touch, this);
	
	Enemy* enemy3 = Enemy::createEnemy(EnemyType::BOSS);
	this->addChild(enemy3);

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

void TestLayer::addGem(float time)
{
	int r = random(1, 3);
	GemType gemType = GemType::HP;
	switch (r)
	{
	case 2:
		{
			gemType = GemType::BULLET;
			break;
		}
	case 3:
		{
			gemType = GemType::THUNDER;
			break;
		}
	}
	Gem* gem = Gem::createGem(gemType);
	this->addChild(gem);
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
		for (int i = 0; i < MAX_HP; i ++)
		{
			Sprite* hp = Sprite::createWithSpriteFrameName("player_hp");
			hp->setTag(LayerTag::TAG_HP_1 + i);
			auto size = hp->getContentSize();
			hp->setPosition(size.width * (i + 1), size.height / 2);
			addChild(hp);
		}
		
	}
	int hp = Player::getInstance()->getHp();
	if (hp != _player_hp)
	{
		_player_hp = hp;
		for (int i = 0; i < MAX_HP; i ++)
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

void TestLayer::drawThunder(bool init)
{	
	if (init)
	{
		for (int i = 0; i < MAX_THUNDER; i ++)
		{
			Sprite* thunder = Sprite::createWithSpriteFrameName("gem_thunder");
			thunder->setTag(LayerTag::TAG_SKILL_1 + i);
			auto size = thunder->getContentSize();
			thunder->setPosition(SIZE_WIDTH - (size.width * (MAX_THUNDER - i)), size.height / 2);
			addChild(thunder);
		}
		
	}
	int thunder = Player::getInstance()->getThunder();
	if (thunder != _player_thunder)
	{
		_player_thunder = thunder;
		for (int i = 0; i < MAX_THUNDER; i ++)
		{
			if (_player_thunder > i)
			{
				getChildByTag(LayerTag::TAG_SKILL_1 + i)->setVisible(true);
			}
			else
			{
				getChildByTag(LayerTag::TAG_SKILL_1 + i)->setVisible(false);
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
	Player* player = Player::getInstance();
	if (player->getHp() != _player_hp)
	{
		drawHp();
	}
	if (player->getThunder() != _player_thunder)
	{
		drawHp();
	}
	if (player->getScore() != _score)
	{
		drawScore();
	}
}