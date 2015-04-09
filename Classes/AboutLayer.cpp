#include "AboutLayer.h"
#include "MenuLayer.h"
USING_NS_CC;

Scene* AboutLayer::scene()
{
    Scene *scene = Scene::create();
    AboutLayer *layer = AboutLayer::create();
    scene->addChild(layer);
    return scene;
}

bool AboutLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    //获取设备尺寸
    auto size = Director::getInstance()->getWinSize();
    
    //背景
    Sprite* logo = Sprite::create(IMG_BG + "img_bg_logo.jpg");
    logo->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(logo);
    
	CallFunc *func1 = CallFunc::create(CC_CALLBACK_0(AboutLayer::a, this));
    CallFunc *func2 = CallFunc::create(CC_CALLBACK_0(AboutLayer::b, this));
    CallFunc *func3 = CallFunc::create(CC_CALLBACK_0(AboutLayer::c, this));
    CallFunc *func4 = CallFunc::create(CC_CALLBACK_0(AboutLayer::d, this));
    CallFunc *func5 = CallFunc::create(CC_CALLBACK_0(AboutLayer::e, this));
    CallFunc *func6 = CallFunc::create(CC_CALLBACK_0(AboutLayer::f, this));
    this->runAction(Sequence::create(func1,DelayTime::create(4),func2,DelayTime::create(4),func3,DelayTime::create(4),func4,DelayTime::create(4),func5,DelayTime::create(4),func6,NULL));
    
    //添加一个按钮用于切换至Menu菜单场景
	MenuItemImage * back= MenuItemImage::create(IMG_MENU + "backHomeWord.png", IMG_MENU + "backHomeWord.png",CC_CALLBACK_1(AboutLayer::backMenu, this));
    
    //利用一个菜单项创建一个Menu
    Menu* menu =Menu::create(back,NULL);
    menu->setPosition(Vec2(size.width/2, 30));
    addChild(menu);
    return true;
}

void AboutLayer::a()
{
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(AboutLayer::remove, this));
    auto size = Director::getInstance()->getWinSize();
    Sprite* girl1 = Sprite::create(IMG_ABOUT + "aboutGirl1.png");
    girl1->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(girl1,1,11);
    girl1->runAction(Sequence::create(DelayTime::create(2),FadeOut::create(2),func,NULL));
}

void AboutLayer::b()
{
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(AboutLayer::remove, this));
    auto size = Director::getInstance()->getWinSize();
    Sprite* b = Sprite::create(IMG_ABOUT + "heroBigShow.png");
    b->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(b,1,11);
    b->runAction(Sequence::create(FadeIn::create(1),DelayTime::create(2),FadeOut::create(1),func,NULL));
}
void AboutLayer::c()
{
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(AboutLayer::remove, this));
    auto size = Director::getInstance()->getWinSize();
    Sprite* c = Sprite::create(IMG_ABOUT + "plane1Show.png");
    c->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(c,1,11);
    c->runAction(Sequence::create(FadeIn::create(1),DelayTime::create(2),FadeOut::create(1),func,NULL));
}
void AboutLayer::d()
{
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(AboutLayer::remove, this));
    auto size = Director::getInstance()->getWinSize();
    Sprite* d = Sprite::create(IMG_ABOUT + "plane2Show.png");
    d->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(d,1,11);
    d->runAction(Sequence::create(FadeIn::create(1),DelayTime::create(2),FadeOut::create(1),func,NULL));
}
void AboutLayer::e()
{
    CallFunc *func = CallFunc::create(CC_CALLBACK_0(AboutLayer::remove, this));
    auto size = Director::getInstance()->getWinSize();
    Sprite* e = Sprite::create(IMG_ABOUT + "plane3Show.png");
    e->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(e,1,11);
    e->runAction(Sequence::create(FadeIn::create(1),DelayTime::create(2),FadeOut::create(1),func,NULL));
}
void AboutLayer::f()
{
    auto size = Director::getInstance()->getWinSize();
    Sprite* girl2 = Sprite::create(IMG_ABOUT + "aboutGirl2.png");
    girl2->setPosition(Vec2(size.width*0.5,size.height*0.5));
    addChild(girl2,1,11);
    girl2->runAction(Sequence::create(FadeIn::create(2),DelayTime::create(2),NULL));
}
void AboutLayer::remove()
{
    removeChildByTag(11, true);
}

void AboutLayer::backMenu(Ref* psend){
    //切换到"菜单"场景
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
}
