#include "PauseLayer.h"

bool PauseLayer::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100))) 
	{
        return  false;
    }
    auto winSize = Director::getInstance()->getWinSize();
    
    MenuItemImage* play = MenuItemImage::create(IMG_MENU + "play.png", IMG_MENU + "play.png", CC_CALLBACK_1(PauseLayer::doResume, this));
    //play->setTag(10);
    play->setPosition(Vec2(winSize.width/2, winSize.height/2+50));
    
    MenuItemImage* back= MenuItemImage::create(IMG_MENU + "backHome.png", IMG_MENU + "backHome.png", CC_CALLBACK_1(PauseLayer::doBack, this));
    //back->setTag(20);
    back->setPosition(Vec2(winSize.width/2, winSize.height/2-50));
    
    Menu* menu = Menu::create(play, back, NULL);
    menu->setAnchorPoint(Vec2(0, 0));
    addChild(menu, 1);
    menu->setPosition(0, 0);
    
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PauseLayer::TouchBegan, this);
	listener->setSwallowTouches(true);  
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);  


    return true;
}

bool PauseLayer::TouchBegan(Touch* touch, Event* event)
{
	return true;
}

// 触摸被吞掉了，这个回调不会调用
void PauseLayer::doResume(Ref* pSender)
{
    log("resume!");
	Director::getInstance()->resume();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    this->removeFromParentAndCleanup(true);
}

void PauseLayer::doBack(Ref* pSender)
{
    log("doBack!");
	Player::getInstance()->unscheduleAllCallbacks();
	Config::getInstance()->removeAll();

	Director::getInstance()->resume();
    Director::getInstance()->replaceScene(TransitionPageTurn::create(1, MenuLayer::scene(),true));
}