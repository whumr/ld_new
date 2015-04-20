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
		_radian = _circle / (time / Director::getInstance()->getAnimationInterval());
		return true;
	}
	return false;
}

void CircleBy::update(float time)
{
	//Vec2 position = _target->getPosition();
	//_target->setPosition(position + Vec2());
	//_current_radian += _radian;
	////float x = 
	//Vec2 p = Vec2(_center.x + _radius * sin(_radian), _center.y + _radius * cos(_radian));
	_current_radian += _radian;
	float x = _radius * sin(_current_radian);
	float y = _radius * cos(_current_radian);
	Vec2 p = _clockwise ? _center + Vec2(x, y) : _center - Vec2(x, y);

	_target->setPosition(p);
	log("%f\t%f", p.x, p.y);
}