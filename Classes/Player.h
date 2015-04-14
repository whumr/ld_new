#ifndef __ld__Player__
#define __ld__Player__

#include "Config.h"
#include "Bullet.h"

class Player : public Sprite
{
public:		
	~Player();
	static const PlanType DEFAULT_TYPE = PlanType::YELLOW;
    static Player* getInstance(PlanType type = DEFAULT_TYPE);

	CC_SYNTHESIZE(PlanType, _type, Type);
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType);
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _bullet, Bullet);
	CC_SYNTHESIZE(int, _kill, Kill);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);

	//选择飞机图片
	void initPlane();
	//被击中
	void shot();
	
    //void downHp();//掉血
    //void addHp();//加血
    //void addScore(int _value);//加分
    //void addKillCount(int _value);//加杀敌数
    //bool isDead;//是否死亡
    //int strongTime;//无敌时间
    //bool isStrong;//是否处于无敌时间
    //int strongCount;//无敌时的计数器
    //void strongIng(float dt);//处理无敌时的闪烁等处理
    
private:
	bool init();
	void shoot(float time);
	//挂掉
	void die();
    
    //void playerInit();//初始化函数
};

#endif /* defined(__ld__Player__) */
