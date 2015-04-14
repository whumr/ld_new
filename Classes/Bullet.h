#ifndef __ld__Bullet__
#define __ld__Bullet__

#include "Config.h"
#include "Player.h"
#include "Enemy.h"

class Bullet : public Sprite
{	
public:	
    //ʵ��������
    static Bullet* createBullet(BulletType type);
	CC_SYNTHESIZE(Vec2, _speed, Speed);
	CC_SYNTHESIZE(bool, _enemy, Enemy);
	CC_SYNTHESIZE(BulletType, _type, Type);

private:
	bool init();
	void update(float time);
	void checkEnemyShot();
	void checkPlayerShot();

//public:
//    //ʵ��������
//    static Bullet* createBullet(const char* _fileName, float _speed, Point _position, int _type);
//    
//private:
//    //��ʼ������
//    void bulletInit(float _speed,Point _position,int _type);
//    void update(float time);//�߼�
//    float speed;//�ƶ��ٶ�
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
