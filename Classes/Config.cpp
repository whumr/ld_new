#include "Config.h"
#include "cocos2d.h"
USING_NS_CC;

bool soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);

Config::~Config()
{
	enemyArray.clear();
	bulletArray.clear();
}

Vector<Enemy*> Config::getEnemyArray(bool clear = false)
{
	if (clear)
	{
		enemyArray.clear();
	}
	return enemyArray;
}

Vector<Bullet*> Config::getBulletArray(bool clear = false)
{
	if (clear)
	{
		bulletArray.clear();
	}
	return bulletArray;
}