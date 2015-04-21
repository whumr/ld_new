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

class MoveStrict : public ActionInterval
{
public:
	static MoveStrict* create(float angleCW, float velocity);

private:
	bool init(float angleCW, float velocity);
    void update(float time);

	//顺时针角度
	float _angleCW;
	//每秒速度
	float _velocity;
	//每一帧x坐标变换
	float _v_x;
	//每一帧y坐标变换
	float _v_y;
};
#endif