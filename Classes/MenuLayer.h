#ifndef __ld__MenuLayer__
#define __ld__MenuLayer__

#include "Config.h"
#include "SettingLayer.h"
#include "AboutLayer.h"
#include "ScoreLayer.h"
#include "TestLayer.h"

class MenuLayer : public Layer
{
public:    
    static Scene* scene();
    CREATE_FUNC(MenuLayer);

private:
	bool init();
    //当点击"Play"菜单项触发的回调函数
    void playIsPressed(Ref* psend);
    //当点击"Score"菜单项触发的回调函数
    void scoreIsPressed(Ref* psend);
    //当点击"About"菜单项触发的回调函数
    void aboutIsPressed(Ref* psend);
    //当点击"settings"菜单项触发的回调函数
    void setttingsIsPressed(Ref* psend);


    void testIsPressed(Ref* psend);
	void loadCallback(Texture2D* texture, string name);
};
#endif /* defined(__ld__MenuLayer__) */