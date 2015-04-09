#include "SettingLayer.h"
#include "MenuLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

extern bool soundOn;

Scene* SettingLayer::scene()
{
    Scene *scene = Scene::create();
    SettingLayer *layer = SettingLayer::create();
    scene->addChild(layer);
    return scene;
}

bool SettingLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    //获取设备尺寸
    auto size = Director::getInstance()->getWinSize();
    
    //背景
    Sprite* bg = Sprite::create("img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
    
	auto conf = Configuration::getInstance();
    //音效
	MenuItemFont *itemOn = MenuItemFont::create(conf->getValue("setting.soundUp").asString(), CC_CALLBACK_1(SettingLayer::soundUp, this));
	itemOn->setColor(Color3B(255, 0, 0));
	MenuItemFont *itemDown = MenuItemFont::create(conf->getValue("setting.soundDown").asString(), CC_CALLBACK_1(SettingLayer::soundDown, this));
    itemDown->setColor(Color3B(255, 0, 0));

    //利用一个菜单项创建一个Menu
    Menu* menu = Menu::create(itemOn,itemDown,NULL);
    menu->setPosition(Vec2(size.width*2/5, size.height/2));
    addChild(menu);
    //pMenu->alignItemsHorizontallyWithPadding(40);    //设置各item的横向间隔
    menu->alignItemsVerticallyWithPadding(40);       //设置各item的竖向间隔
    
    ////注释
    //Label* annotation = Label::createWithSystemFont(conf->getValue("setting.rollbartip").asString(), "Helvetica", 15);
    //annotation->setPosition(Vec2(size.width*0.5-5,size.height*0.5+10));
    //annotation->setColor(Color3B(255, 0, 0));
    //addChild(annotation);
    
    //添加对号图片，显示当前选择的操作
	selectd = Sprite::create("selected.png");
    if(soundOn)
    {
        selectd->setPosition(Vec2(size.width*4/5, size.height/2+38));
    }
	else
    {
        selectd->setPosition(Vec2(size.width*4/5, size.height/2-35));  
    }
    addChild(selectd,1,1);

    //添加一个按钮用于返回Menu
	MenuItemImage * back= MenuItemImage::create("backHomeWord.png", "backHomeWord.png",CC_CALLBACK_1(SettingLayer::backMenu, this));
    Menu* backMenu =Menu::create(back,NULL);
    backMenu->setPosition(Vec2(size.width/2, 30));
    addChild(backMenu);
    
    return true;
}

void SettingLayer::soundUp(Ref* psend)
{
    soundOn = true;
    auto size = Director::getInstance()->getWinSize();
	selectd->setPosition(Vec2(size.width*4/5, size.height/2+38)); 
	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("menuMusic.mp3",true);
	}
	else
	{
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
}

void SettingLayer::soundDown(Ref* psend)
{
    soundOn = false;
    auto size = Director::getInstance()->getWinSize();
	selectd->setPosition(Vec2(size.width*4/5, size.height/2-35));
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void SettingLayer::backMenu(Ref* psend){
    //切换到"菜单"场景
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
	UserDefault::getInstance()->setBoolForKey("soundOn", soundOn);
}
