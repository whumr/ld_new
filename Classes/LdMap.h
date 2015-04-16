#ifndef __ld__LdMap__
#define __ld__LdMap__

#include "Config.h"

class LdMap : public cocos2d::Layer
{
public:
    CREATE_FUNC(LdMap);
    
private:
	bool init();
    //逻辑
    void update(float time);
    //生命周期函数的退出
    void onExit();

    ParallaxNode *_backgroundNode;
};
#endif