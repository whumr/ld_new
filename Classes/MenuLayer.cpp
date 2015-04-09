#include "MenuLayer.h"
#include "SimpleAudioEngine.h"
#include "SettingLayer.h"
#include "AboutLayer.h"
#include "ScoreLayer.h"

using namespace CocosDenshion;

extern bool soundOn;

Scene* MenuLayer::scene()
{
    Scene *scene = Scene::create();
    MenuLayer *layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }       
    //���Ų˵�����������
    if (soundOn)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("menuMusic.mp3",true);
	}
    //��ȡ�����豸�ĳߴ�
    auto size = Director::getInstance()->getWinSize();
    
    //����Menu����
    Sprite* bg = Sprite::create("img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
    
    Sprite* logo = Sprite::create("LOGO.png");
    logo->setPosition(Vec2(size.width*0.5,size.height*2/3+15));
    addChild(logo);
    
    //����Menu�˵���-play
	MenuItemImage *itemPlay= MenuItemImage::create("play_nor.png", "play_pre.png",CC_CALLBACK_1(MenuLayer::playIsPressed, this));
    
    //����Menu�˵���-score
    MenuItemImage *itemScore= MenuItemImage::create("score_nor.png", "score_pre.png",CC_CALLBACK_1(MenuLayer::scoreIsPressed, this));
    itemScore->setPosition(Vec2(0,-itemScore->getContentSize().height-20));
    
    //����Menu�˵���-about
    MenuItemImage *itemAbout= MenuItemImage::create("about_nor.png", "about_pre.png",CC_CALLBACK_1(MenuLayer::aboutIsPressed, this));
    itemAbout->setPosition(Vec2(0,-itemScore->getContentSize().height*2-40));
    
    //����Menu�˵���-settings
    MenuItemImage *itemSettings = MenuItemImage::create("setting.png", "setting.png",CC_CALLBACK_1(MenuLayer::SetttingsIsPressed, this));
    itemSettings->setPosition(Vec2(0,-itemScore->getContentSize().height*3-40));
    
    //����3���˵����Menu�˵�
    Menu * menu = Menu::create(itemPlay,itemScore,itemAbout,itemSettings,NULL);
    menu->setPosition(Vec2(size.width/2, size.height/3-10));
    addChild(menu);
    menu->alignItemsVerticallyWithPadding(10);
    
    return true;
}

//�˵���Play������ʱ�Ļص�����
void MenuLayer::playIsPressed(Ref* psend){
    //�л���"�ؿ�"����
    //Director::getInstance()->replaceScene(TransitionFade::create(1, Level::scene()));

}

//�˵���High Scores������ʱ�Ļص�����
void MenuLayer::scoreIsPressed(Ref* psend){
    //�л������߷֡�����
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, ScoreLayer::scene(),false));
}

//�˵���About������ʱ�Ļص�����
void MenuLayer::aboutIsPressed(Ref* psend){
    //�л��������ڡ�����
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, AboutLayer::scene(),false));
}

//�˵���Settings������ʱ�Ļص�����
void MenuLayer::SetttingsIsPressed(Ref* psend){
    //�л�����Settings������
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, SettingLayer::scene(),false));
}
