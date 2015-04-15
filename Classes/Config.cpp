#include "Config.h"

bool soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);

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
	return true;
}

void Config::addEnemy(Sprite* enemy)
{
	enemyArray.pushBack(enemy);
}