#ifndef __ld__Enemy__
#define __ld__Enemy__

#include "cocos2d.h"
USING_NS_CC;

class Enemy : public Sprite
{
public:
    //实例化函数
    static Enemy* createEnemy(const char* fileName,int _type,int _way);
    //价值多少分数
    int scoreValue;
    //血量
    int hp;
    int enemyType;
	bool isDead;
	void enemyDead();
private:
    //初始化
    void enemyInit(const char* fileName,int _type,int _way);
    
    //敌人逻辑
    void update(float time);
    //是否已经运动过了
    bool isActed;	
	int timeCount1;
    //当前敌人类型
    int way;
    void enemyShoot();
    void shootMany(float f);
    int shootManyCount;
    void shootFive(Point playerPoint);
    void shootOne(Point playerPoint);    
    
    
};

#endif /* defined(__ld__Enemy__) */
