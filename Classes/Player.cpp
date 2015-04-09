#include "Player.h"

int playerType = 1;
extern int sceneLevel;

Player* Player::createPlayer(const char* fileName){
    Player* player = new Player();
    if(player && player->initWithFile(fileName)){
        player->autorelease();
        player->playerInit();
        return player;
    }
    CC_SAFE_DELETE(player);
    return NULL;
}

void Player::playerInit()
{    
    hpMax =3;//��ʼ��Ѫ������Ϊ3
    strongTime=5*60;//��ʼ���޵�ʱ��5��
	isDead = false;
	isStrong = false;
}

//���ӻ��ַ���
void Player::addScore(int _value){
    score+=_value;
    std::string strScore=Convert2String(score);
    Label* ttf = (Label*)LevelScene::sharedLevelScene()->getChildByTag(tag_scoreTTF);
    ttf->setString(strScore.c_str());
}

//Layer* getLevelScene(int iLevel)
//{
//    return LevelScene::sharedLevelScene();
//}

//����ɱ����
void Player::addKillCount(int _value)
{
    killCount+=_value;
    std::string strKillCount=Convert2String(killCount);
    Label* ttf = (Label*)LevelScene::sharedLevelScene()->getChildByTag(tag_killsCountTTF);
    ttf->setString(strKillCount.c_str());
    
    {
        if(sceneLevel==1)
        {
            //�洢����
            int oldScore =atoi(UserDefault::getInstance()->getStringForKey("user_score2","-1").c_str());
            if(score>oldScore){
                UserDefault::getInstance()->setStringForKey("user_score2", Convert2String(score));
                UserDefault::getInstance()->flush();
                LevelScene::sharedLevelScene()->isGetNewRecord = true;
            }
        }else if (sceneLevel==2)
        {
            //�洢����
            int oldScore =atoi(UserDefault::getInstance()->getStringForKey("user_score3","-1").c_str());
            if(score>oldScore){
                UserDefault::getInstance()->setStringForKey("user_score3", Convert2String(score));
                UserDefault::getInstance()->flush();
                LevelScene::sharedLevelScene()->isGetNewRecord = true;
            }
        }
        
        
        //����ʤ������
        if(killCount>=100)
            LevelScene::sharedLevelScene()->winGame();
    }
}

//���ǵ�Ѫ������Ĭ��ÿ�ε�һ��Ѫ��
void Player::downHp(){
    if(isStrong){
        return;
    }
    hp-=1;
    if(hp<=0){
        this->setVisible(false);
        isDead=true;

        //����ʧ�ܽ���
        LevelScene::sharedLevelScene()->lostGame();
    }else{
        //�������Ѫ��icon�������и���
        switch (hp) {
            case 1:
                LevelScene::sharedLevelScene()->removeChildByTag(tag_playerHp2, true);
                break;
                
            case 2:
                LevelScene::sharedLevelScene()->removeChildByTag(tag_playerHp3, true);
                break;
        }
        //�����޵�ʱ��
        isStrong=true;
        strongCount=0;
        this->schedule(schedule_selector(Player::strongIng));
    }
}

//���Ǽ�Ѫ������Ĭ��ÿ�μ�һ��Ѫ��
void Player::addHp()
{
    switch(hp)
    {
        case 1:
        {
            Sprite* spHp = Sprite::create("icon_hp.png");
            spHp->setPosition(Vec2(25*2,spHp->getContentSize().height*0.5));
            spHp->setTag(tag_playerHp2);
            LevelScene::sharedLevelScene()->addChild(spHp,10);
            break;
        }
        case 2:
        {
            Sprite* spHp = Sprite::create("icon_hp.png");
            spHp->setPosition(Vec2(25*3,spHp->getContentSize().height*0.5));
            spHp->setTag(tag_playerHp3);
            LevelScene::sharedLevelScene()->addChild(spHp,10);
            break;
        }
        default:
            break;
    }
}

//�����޵�ʱ��ʱ�Ĵ�������
void Player::strongIng(float dt){
    strongCount++;
    if(strongCount>=strongTime){
        this->setVisible(true);
        isStrong=false;
        this->unschedule(schedule_selector(Player::strongIng));
    }else{
        //���Ǵ����޵�ʱ��ʱ����˸Ч��
        if(strongCount%2==0){
            this->setVisible(false);
        }else{
            this->setVisible(true);
        }
    }
}