#ifndef __ld__LdMap__
#define __ld__LdMap__

#include "Config.h"

class LdMap : public cocos2d::Layer
{
public:
    CREATE_FUNC(LdMap);
    
private:
	bool init();
    //�߼�
    void update(float time);
    //�������ں������˳�
    void onExit();

    ParallaxNode *_backgroundNode;
};
#endif