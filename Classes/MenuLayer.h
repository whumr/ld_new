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
    //�����"Play"�˵�����Ļص�����
    void playIsPressed(Ref* psend);
    //�����"Score"�˵�����Ļص�����
    void scoreIsPressed(Ref* psend);
    //�����"About"�˵�����Ļص�����
    void aboutIsPressed(Ref* psend);
    //�����"settings"�˵�����Ļص�����
    void setttingsIsPressed(Ref* psend);


    void testIsPressed(Ref* psend);
	void loadCallback(Texture2D* texture, string name);
};
#endif /* defined(__ld__MenuLayer__) */