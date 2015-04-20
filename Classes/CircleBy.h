#ifndef __ld__CircleBy__
#define __ld__CircleBy__

#include "cocos2d.h"

USING_NS_CC;

class CircleBy : public ActionInterval
{
public:
	static CircleBy* create(float time, Point center, float radius, float circle = M_PI * 2, float start = M_PI / 2, bool clockwise = true);
       
private:
	bool init(float time, Point center, float radius, float circle, float start, bool clockwise);
    void update(float time);
	
	//圆心
	Point _center;
	//半径
	float _radius;
	//起始角度
	float _start;
	//旋转弧度
	float _circle;
	//旋转方向
	bool _clockwise;
	//每次update的弧度
	float _radian;
	//当前旋转弧度
	float _current_radian;
};
#endif