#include "Config.h"
#include "cocos2d.h"
USING_NS_CC;

bool soundOn = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str(), true);