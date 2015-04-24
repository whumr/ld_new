#include "Config.h"

int level = 1;
bool soundOn = true;
float SIZE_WIDTH = 0;
float SIZE_HEIGHT = 0;

static Config *config = nullptr;

Config::~Config()
{
	enemyArray.clear();
	config = nullptr;
}

Config* Config::getInstance()
{
	if (!config)
	{
		config = new Config();
		config->init();
	}
	return config;
}

bool Config::init()
{
	enemyArray.clear();
	bulletArray.clear();
	soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);
	SIZE_WIDTH = Director::getInstance()->getWinSize().width;
	SIZE_HEIGHT = Director::getInstance()->getWinSize().height;
	CCRANDOM_0_1();
	return true;
}

void Config::addEnemy(Sprite* enemy)
{
	enemyArray.pushBack(enemy);
}

void Config::removeEnemy(Sprite* enemy)
{
	enemyArray.eraseObject(enemy);
}

void Config::addBullet(Sprite* bullet)
{
	bulletArray.pushBack(bullet);
}

void Config::removeBullet(Sprite* bullet)
{
	bulletArray.eraseObject(bullet);
}

void Config::removeAll()
{
	for (int i = 0; i < enemyArray.size(); i++) 
	{
		enemyArray.at(i)->removeFromParentAndCleanup(true);
    }
	enemyArray.clear();
	for (int i = 0; i < bulletArray.size(); i++) 
	{
		bulletArray.at(i)->removeFromParentAndCleanup(true);
    }
	bulletArray.clear();
	if (_map)
	{
		_map->unscheduleAllCallbacks();
	}
}

void Config::setMap(Layer* map)
{
	_map = map;
}