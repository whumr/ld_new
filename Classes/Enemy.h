#ifndef __ld__Enemy__
#define __ld__Enemy__

#include "Config.h"
#include "Bullet.h"

class Enemy : public Sprite
{
public:	
	static const EnemyType DEFAULT_TYPE = EnemyType::LOWEST;
    //实例化函数
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
	//void toBattle();
	void shoot(float time);	
	void enemyDead();
	void update(float time);


 //   //初始化
 //   void enemyInit(const char* fileName,int _type,int _way);
 //   
 //   //敌人逻辑
 //   void update(float time);
 //   //是否已经运动过了
 //   bool isActed;	
	//int timeCount1;
 //   //当前敌人类型
 //   int way;
 //   void enemyShoot();
 //   void shootMany(float f);
 //   int shootManyCount;
 //   void shootFive(Point playerPoint);
 //   void shootOne(Point playerPoint);    
};

#endif /* defined(__ld__Enemy__) */
