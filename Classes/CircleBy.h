#ifndef __ld__CircleBy__
#define __ld__CircleBy__

#include "Config.h"

class CircleBy : public ActionInterval
{
public:
	static CircleBy* create(double time, Point center, double radius, double circle = M_PI * 2, double start = M_PI / 2, bool clockwise = true);
       
private:
	bool init(double time, Point center, double radius, double circle, double start, bool clockwise);
    void update(float time);
	
	//圆心
	Point _center;
	//半径
	double _radius;
	//起始角度
	double _start;
	//旋转弧度
	double _circle;
	//旋转方向
	bool _clockwise;
	//每次update的弧度
	double _radian;
	//当前旋转弧度
	double _current_radian;
};

class MoveStrict : public ActionInterval
{
public:
	static MoveStrict* create(double angleCW, float velocity, Size spriteSize);

private:
	bool init(double angleCW, float velocity, Size spriteSize);
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