#include "Trail.h"

void Trail::circleFromLeftTop(Sprite* sprite, float time)
{
	auto contentSize = sprite->getContentSize();
	sprite->runAction(CircleBy::create(10, Vec2(SIZE_WIDTH + contentSize.width, SIZE_HEIGHT + contentSize.height / 2), 
				SIZE_WIDTH, M_PI / 2, M_PI * 3 / 2, false));
}

void Trail::circleFromRightTop(Sprite* sprite, float time)
{
	auto contentSize = sprite->getContentSize();
	sprite->runAction(CircleBy::create(10, Vec2(-contentSize.width, SIZE_HEIGHT + contentSize.height / 2), 
				SIZE_WIDTH, M_PI / 2));		
}

void Trail::moveDown(Sprite* sprite, float velocity)
{
	//sprite->runAction(RepeatForever::create(MoveStrict::create(M_PI, velocity)));
	sprite->runAction(MoveStrict::create(M_PI, velocity, sprite->getContentSize()));
}