#ifndef __ld__MenuLayer__
#define __ld__MenuLayer__

#include "cocos2d.h"
USING_NS_CC;

class MenuLayer : public Layer
{
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(MenuLayer);

private:
    //当点击"Play"菜单项触发的回调函数
    void playIsPressed(Ref* psend);
    //当点击"Score"菜单项触发的回调函数
    void scoreIsPressed(Ref* psend);
    //当点击"About"菜单项触发的回调函数
    void aboutIsPressed(Ref* psend);
    //当点击"settings"菜单项触发的回调函数
    void SetttingsIsPressed(Ref* psend);
};
#endif /* defined(__ld__MenuLayer__) */