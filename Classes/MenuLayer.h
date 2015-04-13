#ifndef __ld__MenuLayer__
#define __ld__MenuLayer__

#include "Config.h"
#include "cocos2d.h"
USING_NS_CC;

class MenuLayer : public Layer
{
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(MenuLayer);

private:
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