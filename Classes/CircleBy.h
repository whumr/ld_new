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
	
	//Բ��
	Point _center;
	//�뾶
	double _radius;
	//��ʼ�Ƕ�
	double _start;
	//��ת����
	double _circle;
	//��ת����
	bool _clockwise;
	//ÿ��update�Ļ���
	double _radian;
	//��ǰ��ת����
	double _current_radian;
};

class MoveStrict : public ActionInterval
{
public:
	static MoveStrict* create(double angleCW, float velocity, Size spriteSize);

private:
	bool init(double angleCW, float velocity, Size spriteSize);
    void update(float time);

	//˳ʱ��Ƕ�
	double _angleCW;
	//ÿ���ٶ�
	float _velocity;
	//ÿһ֡x����任
	float _v_x;
	//ÿһ֡y����任
	float _v_y;
};

class MoveRandom : public ActionInterval
{
public:
	static MoveRandom* create(float time, float velocity, Size spriteSize);

private:
	bool init(float time, float velocity, Size spriteSize);
    void update(float time);

	//�����С
	float _min_x;
	float _min_y;
	//˳ʱ��Ƕ�
	double _angleCW;
	//ÿ���ٶ�
	float _velocity;
	//ÿһ֡x����任
	float _v_x;
	//ÿһ֡y����任
	float _v_y;
	//�Ƿ������Ļ
	bool _enter;
	//��������˳�
	float _lasted;
};
#endif