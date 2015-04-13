#ifndef __ld__Bullet__
#define __ld__Bullet__

#include "cocos2d.h"
#include "Config.h"
USING_NS_CC;

class Bullet : public Sprite
{
	enum BulletType{
		PLAYER_YELLOW,
		PLAYER_PURPLE,
		ENMEY_YELLOW
	};
    //实例化函数
    static Bullet* createBullet(BulletType type);
	CC_SYNTHESIZE(Vec2, _speed, Speed);
	CC_SYNTHESIZE(bool, _enemy, Enemy);
	CC_SYNTHESIZE(BulletType, _type, Type);

private:
	bool init();
	void update(float time);

//public:
//    //实例化函数
//    static Bullet* createBullet(const char* _fileName, float _speed, Point _position, int _type);
//    
//private:
//    //初始化函数
//    void bulletInit(float _speed,Point _position,int _type);
//    void update(float time);//逻辑
//    float speed;//移动速度
//    int bulletType;
//    
//    Point bulletPoint;
//    Point enemyPoint;
//    float newSlope;
//    
//    virtual void onExit();
//    
//    int rotation;
//    Point velocity;
};


#endif /* defined(__ld__Bullet__) */
