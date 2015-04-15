#ifndef __ld__Bullet__
#define __ld__Bullet__

#include "Config.h"
#include "Player.h"
#include "Enemy.h"

class Bullet : public Sprite
{	
public:	
    //ÊµÀý»¯º¯Êý
    static Bullet* createBullet(BulletType type);
	CC_SYNTHESIZE(Vec2, _speed, Speed);
	CC_SYNTHESIZE(bool, _enemy, Enemy);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(BulletType, _type, Type);

private:
	bool init();
	void update(float time);
	void checkEnemyShot();
	void checkPlayerShot();
	void die();
};

#endif /* defined(__ld__Bullet__) */