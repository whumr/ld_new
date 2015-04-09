#ifndef __ld__Enemy__
#define __ld__Enemy__

#include "cocos2d.h"
USING_NS_CC;

class Enemy : public Sprite
{
public:
    //ʵ��������
    static Enemy* createEnemy(const char* fileName,int _type,int _way);
    //��ֵ���ٷ���
    int scoreValue;
    //Ѫ��
    int hp;
    int enemyType;
	bool isDead;
	void enemyDead();
private:
    //��ʼ��
    void enemyInit(const char* fileName,int _type,int _way);
    
    //�����߼�
    void update(float time);
    //�Ƿ��Ѿ��˶�����
    bool isActed;	
	int timeCount1;
    //��ǰ��������
    int way;
    void enemyShoot();
    void shootMany(float f);
    int shootManyCount;
    void shootFive(Point playerPoint);
    void shootOne(Point playerPoint);    
    
    
};

#endif /* defined(__ld__Enemy__) */
