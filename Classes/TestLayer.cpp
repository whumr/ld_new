#include "TestLayer.h"
#include "MenuLayer.h"
#include "HEnemy.h"

Scene* TestLayer::scene()
{
    Scene *scene = Scene::create();
    TestLayer *layer = TestLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TestLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    //获取设备尺寸
    auto size = Director::getInstance()->getWinSize();
    
    //背景
    Sprite* bg = Sprite::create(IMG_BG + "img_bg_logo.jpg");
    bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(bg);
        
	//Sprite* s = Sprite::create("enemy_bug.png");
	//s->setPosition(size.width/2, size.height/2);
	//addChild(s);


	HEnemy* enemy = HEnemy::createEnemy((IMG + "enemy_bug.png").c_str(), 0, 0);
    addChild(enemy);

    //添加一个按钮用于返回Menu
	MenuItemImage * back= MenuItemImage::create(IMG_MENU + "backHomeWord.png", IMG_MENU + "backHomeWord.png",CC_CALLBACK_1(TestLayer::backMenu, this));
    Menu* backMenu =Menu::create(back,NULL);
    backMenu->setPosition(Vec2(size.width/2, 30));
    addChild(backMenu);
    
    return true;
}

void TestLayer::backMenu(Ref* psend){
    //切换到"菜单"场景
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
}
