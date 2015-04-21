#include "CircleBy.h"

CircleBy* CircleBy::create(float time, Point center, float radius, float circle, float start, bool clockwise)
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
       
bool CircleBy::init(float time, Point center, float radius, float circle, float start, bool clockwise)
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
	float x = _radius * sin(_current_radian);
	float y = _radius * cos(_current_radian);
	_target->setPosition(_center + Vec2(x, y));
}



MoveStrict* MoveStrict::create(float angleCW, float velocity)
{
	MoveStrict* moveStrict = new MoveStrict();
    if (moveStrict && moveStrict->init(angleCW, velocity))
    {
        moveStrict->autorelease();
        return moveStrict;
    }
    CC_SAFE_DELETE(moveStrict);
    return nullptr;
}

bool MoveStrict::init(float angleCW, float velocity)
{
	_angleCW = angleCW;
	_velocity = velocity * Director::getInstance()->getAnimationInterval();
	_v_x = _velocity * sin(_angleCW);
	_v_y = _velocity * cos(_angleCW);
	return true;
}

void MoveStrict::update(float time)
{
	auto position = _target->getPosition();
	_target->setPosition(position + Vec2(_v_x , _v_y));
}