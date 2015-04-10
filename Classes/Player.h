#ifndef __ld__Player__
#define __ld__Player__

#include "cocos2d.h"
USING_NS_CC;

class Player : public Sprite
{
public:
	enum PlanType{
		YELLOW,
		RED,
		BLUE
	};
	~Player();
    static Player* getInstance();

	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _bullet, Bullet);
	CC_SYNTHESIZE(int, _kill, Kill);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);
	CC_SYNTHESIZE(PlanType, _type, Type);


    //int hp;//血量
    //int hpMax;//血量最大值
    //int score;//分数
    //int killCount;//杀敌数
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
    
    //void playerInit();//初始化函数
};

#endif /* defined(__ld__Player__) */
