#include "Config.h"

bool soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);

static Config* config = NULL;

Config::~Config()
{
	enemyArray.clear();
}

Config* Config::getInstance()
{
	if (!config)
	{
		config = new Config();
		if(config && config->init())
		{
			config->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(config);
			config = NULL;
		}
	}
	return config;
}

Vector<Sprite*> Config::getEnemyArray(bool clear)
{
	if (clear)
	{
		enemyArray.clear();
	}
	return enemyArray;
}

bool Config::init()
{
	return true;
}