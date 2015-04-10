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


    //int hp;//Ѫ��
    //int hpMax;//Ѫ�����ֵ
    //int score;//����
    //int killCount;//ɱ����
    //void downHp();//��Ѫ
    //void addHp();//��Ѫ
    //void addScore(int _value);//�ӷ�
    //void addKillCount(int _value);//��ɱ����
    //bool isDead;//�Ƿ�����
    //int strongTime;//�޵�ʱ��
    //bool isStrong;//�Ƿ����޵�ʱ��
    //int strongCount;//�޵�ʱ�ļ�����
    //void strongIng(float dt);//�����޵�ʱ����˸�ȴ���
    
private:
	bool init();
    
    //void playerInit();//��ʼ������
};

#endif /* defined(__ld__Player__) */
