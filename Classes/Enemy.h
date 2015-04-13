#ifndef __ld__Enemy__
#define __ld__Enemy__

#include "cocos2d.h"
USING_NS_CC;

class Enemy : public Sprite
{
public:
	enum EnemyType{
		LOWEST,
		LOW,
		NORMAL,
		BETTER,
		BOSS
	};
    //实例化函数
    static Enemy* createEnemy(EnemyType type);
	void enemyDead();
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);
	CC_SYNTHESIZE(EnemyType, _type, Type);

private:
	bool init();
	void toBattle();
	void shoot();



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
