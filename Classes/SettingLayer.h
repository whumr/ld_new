#ifndef __ld__SettingLayer__
#define __ld__SettingLayer__

#include "cocos2d.h"
USING_NS_CC;

class SettingLayer : public Layer
{
    
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(SettingLayer);
    
private:
	Sprite *selectd;
    void soundUp(Ref* psend);
    void soundDown(Ref* psend);    
    void backMenu(Ref* psend);    
};
#endif /* defined(__ld__SettingLayer__) */
