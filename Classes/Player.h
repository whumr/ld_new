#ifndef __ld__Player__
#define __ld__Player__

#include "Config.h"
#include "Bullet.h"

class Player : public Sprite
{
public:			
	static const PlanType DEFAULT_TYPE = PlanType::YELLOW;
    static Player* getInstance();

	~Player();

	PlanType _type;
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType);
	CC_SYNTHESIZE(int, _hp, Hp);
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(int, _bullet, Bullet);
	CC_SYNTHESIZE(int, _kill, Kill);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(bool, _dead, Dead);
	CC_SYNTHESIZE(float, _shootDelay, ShootDelay);
	CC_SYNTHESIZE(int, _thunder, Thunder);

	//ѡ��ɻ�ͼƬ
	void initPlane();
	//������
	void shot();
	void setType(PlanType type);
	//�Ե���
	void addGem(GemType gemType);
	    
private:
	bool init();
	void shoot(float time);
	//�ҵ�
	void die();
};

#endif /* defined(__ld__Player__) */