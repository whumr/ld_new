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
	
	//Բ��
	Point _center;
	//�뾶
	float _radius;
	//��ʼ�Ƕ�
	float _start;
	//��ת����
	float _circle;
	//��ת����
	bool _clockwise;
	//ÿ��update�Ļ���
	float _radian;
	//��ǰ��ת����
	float _current_radian;
};

class MoveStrict : public ActionInterval
{
public:
	static MoveStrict* create(float angleCW, float velocity);

private:
	bool init(float angleCW, float velocity);
    void update(float time);

	//˳ʱ��Ƕ�
	float _angleCW;
	//ÿ���ٶ�
	float _velocity;
	//ÿһ֡x����任
	float _v_x;
	//ÿһ֡y����任
	float _v_y;
};
#endif