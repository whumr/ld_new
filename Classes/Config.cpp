#include "Config.h"

bool soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);
int level = 1;

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