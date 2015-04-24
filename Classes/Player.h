#ifndef __ld__Player__
#define __ld__Player__

#include "Config.h"
#include "Bullet.h"

class Player : public Sprite
{
public:			
	static const PlanType DEFAULT_TYPE = PlanType::YELLOW;
    static Player* getInstance();

	~Player();

	PlanType _type;
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType);
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _bullet, Bullet);
	CC_SYNTHESIZE(int, _kill, Kill);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);
	CC_SYNTHESIZE(int, _thunder, Thunder);

	//选择飞机图片
	void initPlane();
	//被击中
	void shot();
	void setType(PlanType type);
	//吃道具
	void addGem(GemType gemType);
	    
private:
	bool init();
	void shoot(float time);
	//挂掉
	void die();
};

#endif /* defined(__ld__Player__) */