#include "LdMap.h"

bool LdMap::init(){
    string fileName = IMG_BG + String::createWithFormat("img_bg_level_%d.jpg", level)->getCString();
    Sprite* para1 = Sprite::create(fileName);    
    para1->setAnchorPoint(Vec2(0, 0));
	para1->setPosition(0, 0);
	para1->setTag(1);
	Sprite* para2 = Sprite::create(fileName);
    para2->setAnchorPoint(Vec2(0, 0));
	para2->setPosition(0, para2->getContentSize().height);
	para2->setTag(2);
    
	auto node = Node::create();     
	node->addChild(para1);     
	node->addChild(para2);     
	node->setTag(1); 

    _backgroundNode = ParallaxNode::create();
    _backgroundNode->addChild(node, 1, Vec2(0, 1.0f), Vec2(0, 0));
    this->addChild(_backgroundNode);
    this->scheduleUpdate();
	return true;
}

void LdMap::update(float time){
	auto y = _backgroundNode->getPositionY() - 1;     
	_backgroundNode->setPositionY(y);       
	auto node = _backgroundNode->getChildByTag(1);     
	auto bg1 = node->getChildByTag(1);     
	auto bg2 = node->getChildByTag(2);     
	//这里需要先进行一下坐标的转化，转化为相对于当前层的坐标     
	auto point1 = node->convertToWorldSpace(bg1->getPosition());     
	point1 = this->convertToNodeSpace(point1);     
	if(point1.y < -bg1->getContentSize().height)     
	{         
		bg1->setPositionY(bg2->getPositionY() + bg2->getContentSize().height);     
	}       
	auto point2 = node->convertToWorldSpace(bg2->getPosition());     
	point2 = this->convertToNodeSpace(point2);     
	if(point2.y < -bg2->getContentSize().height)     
	{         
		bg2->setPositionY(bg1->getPositionY() + bg1->getContentSize().height);     
	}
}

void LdMap::onExit(){
    //解除更新函数
    this->unscheduleUpdate();
    Layer::onExit();
}
