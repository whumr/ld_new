#ifndef __ld__Player__
#define __ld__Player__

#include "Config.h"
#include "Bullet.h"

class Player : public Sprite
{
public:		
	~Player();
	static const PlanType DEFAULT_TYPE = PlanType::YELLOW;
    static Player* getInstance(PlanType type = DEFAULT_TYPE);

	CC_SYNTHESIZE(PlanType, _type, Type);
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType);
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _bullet, Bullet);
	CC_SYNTHESIZE(int, _kill, Kill);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);

	//ѡ��ɻ�ͼƬ
	void initPlane();
	//������
	void shot();
	
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
	void shoot(float time);
	//�ҵ�
	void die();
    
    //void playerInit();//��ʼ������
};

#endif /* defined(__ld__Player__) */
