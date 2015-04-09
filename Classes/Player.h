#ifndef __ld__Player__
#define __ld__Player__

#include "cocos2d.h"
USING_NS_CC;

class Player : public Sprite
{
public:
    static Player* createPlayer(const char* fileName);//ʵ������
    int hp;//Ѫ��
    int hpMax;//Ѫ�����ֵ
    int score;//����
    int killCount;//ɱ����
    void downHp();//��Ѫ
    void addHp();//��Ѫ
    void addScore(int _value);//�ӷ�
    void addKillCount(int _value);//��ɱ����
    bool isDead;//�Ƿ�����
    int strongTime;//�޵�ʱ��
    bool isStrong;//�Ƿ����޵�ʱ��
    int strongCount;//�޵�ʱ�ļ�����
    void strongIng(float dt);//�����޵�ʱ����˸�ȴ���
    
private:
    
    void playerInit();//��ʼ������
};

#endif /* defined(__ld__Player__) */
