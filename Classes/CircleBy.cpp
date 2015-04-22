#include "CircleBy.h"

CircleBy* CircleBy::create(double time, Point center, double radius, double circle, double start, bool clockwise)
{
	CircleBy* circleBy = new CircleBy();
    if (circleBy && circleBy->init(time, center, radius, circle, start, clockwise))
    {
        circleBy->autorelease();
        return circleBy;
    }
    CC_SAFE_DELETE(circleBy);
    return nullptr;
}
       
bool CircleBy::init(double time, Point center, double radius, double circle, double start, bool clockwise)
{
	if (ActionInterval::initWithDuration(time))
	{
		_center = center;
		_radius = radius;
		_clockwise = clockwise;
		_circle = circle;
		_start = start;
		_current_radian = start;
		_radian = _circle / time * Director::getInstance()->getAnimationInterval();
		return true;
	}
	return false;
}

void CircleBy::update(float time)
{
	_current_radian = _clockwise ? _current_radian + _radian : _current_radian - _radian;
	double x = _radius * sin(_current_radian);
	double y = _radius * cos(_current_radian);
	_target->setPosition(_center + Vec2(x, y));
}




MoveStrict* MoveStrict::create(double angleCW, float velocity, Size spriteSize)
{
	MoveStrict* moveStrict = new MoveStrict();
    if (moveStrict && moveStrict->init(angleCW, velocity, spriteSize))
    {
        moveStrict->autorelease();
        return moveStrict;
    }
    CC_SAFE_DELETE(moveStrict);
    return nullptr;
}

bool MoveStrict::init(double angleCW, float velocity, Size spriteSize)
{	
	_angleCW = angleCW;
	_velocity = velocity * Director::getInstance()->getAnimationInterval();
	_v_x = _velocity * sin(_angleCW);
	_v_y = _velocity * cos(_angleCW);
	float time = MIN((SIZE_WIDTH + spriteSize.width) / abs(_v_x), (SIZE_HEIGHT + spriteSize.height) / abs(_v_y));
	if (ActionInterval::initWithDuration(time))
	{		
		return true;
	}
	return false;
}

void MoveStrict::update(float time)
{
	auto position = _target->getPosition();
	_target->setPosition(position + Vec2(_v_x , _v_y));
}