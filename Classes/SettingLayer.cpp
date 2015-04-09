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
    //��ȡ�豸�ߴ�
    auto size = Director::getInstance()->getWinSize();
    
    //����
    Sprite* bg = Sprite::create("img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
    
	auto conf = Configuration::getInstance();
    //��Ч
	MenuItemFont *itemOn = MenuItemFont::create(conf->getValue("setting.soundUp").asString(), CC_CALLBACK_1(SettingLayer::soundUp, this));
	itemOn->setColor(Color3B(255, 0, 0));
	MenuItemFont *itemDown = MenuItemFont::create(conf->getValue("setting.soundDown").asString(), CC_CALLBACK_1(SettingLayer::soundDown, this));
    itemDown->setColor(Color3B(255, 0, 0));

    //����һ���˵����һ��Menu
    Menu* menu = Menu::create(itemOn,itemDown,NULL);
    menu->setPosition(Vec2(size.width*2/5, size.height/2));
    addChild(menu);
    //pMenu->alignItemsHorizontallyWithPadding(40);    //���ø�item�ĺ�����
    menu->alignItemsVerticallyWithPadding(40);       //���ø�item��������
    
    ////ע��
    //Label* annotation = Label::createWithSystemFont(conf->getValue("setting.rollbartip").asString(), "Helvetica", 15);
    //annotation->setPosition(Vec2(size.width*0.5-5,size.height*0.5+10));
    //annotation->setColor(Color3B(255, 0, 0));
    //addChild(annotation);
    
    //��ӶԺ�ͼƬ����ʾ��ǰѡ��Ĳ���
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

    //���һ����ť���ڷ���Menu
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
    //�л���"�˵�"����
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
	UserDefault::getInstance()->setBoolForKey("soundOn", soundOn);
}
