#ifndef __ld__Enemy__
#define __ld__Enemy__

#include "Config.h"
#include "Bullet.h"
#include "Effect.h"
#include "Player.h"

class Enemy : public Sprite
{
public:	
	static const EnemyType DEFAULT_TYPE = EnemyType::LOWEST;
    //ÊµÀý»¯º¯Êý
    static Enemy* createEnemy(EnemyType type = DEFAULT_TYPE);	
	void shot();
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);
	CC_SYNTHESIZE(EnemyType, _type, Type);
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType);

private:
	bool init();
	void toBattle();
	void shoot(float time);	
	void enemyDead();
	void update(float time);
};

#endif /* defined(__ld__Enemy__) */