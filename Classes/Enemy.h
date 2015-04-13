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
    //ʵ��������
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



 //   //��ʼ��
 //   void enemyInit(const char* fileName,int _type,int _way);
 //   
 //   //�����߼�
 //   void update(float time);
 //   //�Ƿ��Ѿ��˶�����
 //   bool isActed;	
	//int timeCount1;
 //   //��ǰ��������
 //   int way;
 //   void enemyShoot();
 //   void shootMany(float f);
 //   int shootManyCount;
 //   void shootFive(Point playerPoint);
 //   void shootOne(Point playerPoint);    
};

#endif /* defined(__ld__Enemy__) */
