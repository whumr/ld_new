#include "MenuLayer.h"
#include "SettingLayer.h"
#include "AboutLayer.h"
#include "ScoreLayer.h"

#include "TestLayer.h"

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
		SimpleAudioEngine::getInstance()->playBackgroundMusic((MUSIC + "menuMusic.mp3").c_str(), true);
	}
    //��ȡ�����豸�ĳߴ�
    auto size = Director::getInstance()->getWinSize();
    
    //����Menu����
    Sprite* bg = Sprite::create(IMG_BG + "img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
    
    Sprite* logo = Sprite::create(IMG_BG + "logo.png");
    logo->setPosition(Vec2(size.width*0.5,size.height*2/3+15));
    addChild(logo);
    
    //����Menu�˵���-play
	MenuItemImage *itemPlay= MenuItemImage::create(IMG_MENU + "play_nor.png", IMG_MENU + "play_pre.png",CC_CALLBACK_1(MenuLayer::playIsPressed, this));
    
    //����Menu�˵���-score
    MenuItemImage *itemScore= MenuItemImage::create(IMG_MENU + "score_nor.png", IMG_MENU + "score_pre.png",CC_CALLBACK_1(MenuLayer::scoreIsPressed, this));
    itemScore->setPosition(Vec2(0,-itemScore->getContentSize().height-20));
    
    //����Menu�˵���-about
    MenuItemImage *itemAbout= MenuItemImage::create(IMG_MENU + "about_nor.png", IMG_MENU + "about_pre.png",CC_CALLBACK_1(MenuLayer::aboutIsPressed, this));
    itemAbout->setPosition(Vec2(0,-itemScore->getContentSize().height*2-40));
    
    //����Menu�˵���-settings
    MenuItemImage *itemSettings = MenuItemImage::create(IMG_MENU + "setting.png", IMG_MENU + "setting.png",CC_CALLBACK_1(MenuLayer::setttingsIsPressed, this));
    itemSettings->setPosition(Vec2(0,-itemScore->getContentSize().height*3-40));
    
    
	//test
	MenuItemFont *test = MenuItemFont::create("test", CC_CALLBACK_1(MenuLayer::testIsPressed, this));
	test->setColor(Color3B(255, 0, 0));
	test->setPosition(Vec2(0,-itemScore->getContentSize().height*4-40));
	
	
	
	//����3���˵����Menu�˵�
    Menu * menu = Menu::create(itemPlay,itemScore,itemAbout,itemSettings,test,NULL);
    menu->setPosition(Vec2(size.width/2, size.height/3-10));
    addChild(menu);
    menu->alignItemsVerticallyWithPadding(10);
    


	auto textureCache = Director::getInstance()->getTextureCache();
	textureCache->addImageAsync(IMG_PLAYER + "plane1.png", CC_CALLBACK_1(MenuLayer::loadCallback, this, "plan_yellow"));
	textureCache->addImageAsync(IMG_PLAYER + "plane5.png", CC_CALLBACK_1(MenuLayer::loadCallback, this, "plan_red"));
	textureCache->addImageAsync(IMG_PLAYER + "plane22.png", CC_CALLBACK_1(MenuLayer::loadCallback, this, "plan_blue"));
	textureCache->addImageAsync(IMG_PLAYER + "playerBullet.png", CC_CALLBACK_1(MenuLayer::loadCallback, this, IMG_PLAYER + "playerBullet.plist"));
	textureCache->addImageAsync(IMG_ENEMY + "enemy.png", CC_CALLBACK_1(MenuLayer::loadCallback, this, IMG_ENEMY + "enemy.plist"));



    return true;
}

//�˵���Play������ʱ�Ļص�����
void MenuLayer::playIsPressed(Ref* psend)
{
    //�л���"�ؿ�"����
    //Director::getInstance()->replaceScene(TransitionFade::create(1, Level::scene()));

}

//�˵���High Scores������ʱ�Ļص�����
void MenuLayer::scoreIsPressed(Ref* psend)
{
    //�л������߷֡�����
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, ScoreLayer::scene(),false));
}

//�˵���About������ʱ�Ļص�����
void MenuLayer::aboutIsPressed(Ref* psend)
{
    //�л��������ڡ�����
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, AboutLayer::scene(),false));
}

//�˵���Settings������ʱ�Ļص�����
void MenuLayer::setttingsIsPressed(Ref* psend)
{
    //�л�����Settings������
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, SettingLayer::scene(),false));
}


void MenuLayer::testIsPressed(Ref* psend)
{
    //�л�����Settings������
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, TestLayer::scene(),false));
}

void MenuLayer::loadCallback(Texture2D* texture, string name)
{
	if (name.size() > 6 && name.substr(name.length() - 6, 6).compare(".plist") == 0)
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(name, texture);
	}
	else
	{
		auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height));
		SpriteFrameCache::getInstance()->addSpriteFrame(frame, name);
	}	
}