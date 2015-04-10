#include "Player.h"

static Player* player = NULL;

Player* Player::getInstance()
{
	if (!player)
	{
		player = new Player();
		if(player && player->init())
		{
			player->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(player);
			player = NULL;
		}
	}
	return player;
}

bool Player::init()
{
	_hp = 3;
	_score = 0;
	_kill = 0;
	_bullet = 2;
	_speed = 20;
	_shootDelay = 1;
	_type = PlanType::YELLOW;
	this->initWithSpriteFrameName("plan_yellow");
}

Player::~Player()
{
	player = NULL;
}

//Player* Player::createPlayer(const char* fileName){
//    Player* player = new Player();
//    if(player && player->initWithFile(fileName)){
//        player->autorelease();
//        player->playerInit();
//        return player;
//    }
//    CC_SAFE_DELETE(player);
//    return NULL;
//}
//
//void Player::playerInit()
//{    
//    hpMax =3;//初始化血量上限为3
//    strongTime=5*60;//初始化无敌时间5秒
//	isDead = false;
//	isStrong = false;
//}
//
////添加积分分数
//void Player::addScore(int _value){
//    score+=_value;
//    std::string strScore=Convert2String(score);
//    Label* ttf = (Label*)LevelScene::sharedLevelScene()->getChildByTag(tag_scoreTTF);
//    ttf->setString(strScore.c_str());
//}
//
////Layer* getLevelScene(int iLevel)
////{
////    return LevelScene::sharedLevelScene();
////}
//
////添加杀敌数
//void Player::addKillCount(int _value)
//{
//    killCount+=_value;
//    std::string strKillCount=Convert2String(killCount);
//    Label* ttf = (Label*)LevelScene::sharedLevelScene()->getChildByTag(tag_killsCountTTF);
//    ttf->setString(strKillCount.c_str());
//    
//    {
//        if(sceneLevel==1)
//        {
//            //存储分数
//            int oldScore =atoi(UserDefault::getInstance()->getStringForKey("user_score2","-1").c_str());
//            if(score>oldScore){
//                UserDefault::getInstance()->setStringForKey("user_score2", Convert2String(score));
//                UserDefault::getInstance()->flush();
//                LevelScene::sharedLevelScene()->isGetNewRecord = true;
//            }
//        }else if (sceneLevel==2)
//        {
//            //存储分数
//            int oldScore =atoi(UserDefault::getInstance()->getStringForKey("user_score3","-1").c_str());
//            if(score>oldScore){
//                UserDefault::getInstance()->setStringForKey("user_score3", Convert2String(score));
//                UserDefault::getInstance()->flush();
//                LevelScene::sharedLevelScene()->isGetNewRecord = true;
//            }
//        }
//        
//        
//        //调用胜利界面
//        if(killCount>=100)
//            LevelScene::sharedLevelScene()->winGame();
//    }
//}
//
////主角掉血函数（默认每次掉一点血）
//void Player::downHp(){
//    if(isStrong){
//        return;
//    }
//    hp-=1;
//    if(hp<=0){
//        this->setVisible(false);
//        isDead=true;
//
//        //调用失败界面
//        LevelScene::sharedLevelScene()->lostGame();
//    }else{
//        //将界面的血量icon数量进行更新
//        switch (hp) {
//            case 1:
//                LevelScene::sharedLevelScene()->removeChildByTag(tag_playerHp2, true);
//                break;
//                
//            case 2:
//                LevelScene::sharedLevelScene()->removeChildByTag(tag_playerHp3, true);
//                break;
//        }
//        //主角无敌时间
//        isStrong=true;
//        strongCount=0;
//        this->schedule(schedule_selector(Player::strongIng));
//    }
//}
//
////主角加血函数（默认每次加一点血）
//void Player::addHp()
//{
//    switch(hp)
//    {
//        case 1:
//        {
//            Sprite* spHp = Sprite::create("icon_hp.png");
//            spHp->setPosition(Vec2(25*2,spHp->getContentSize().height*0.5));
//            spHp->setTag(tag_playerHp2);
//            LevelScene::sharedLevelScene()->addChild(spHp,10);
//            break;
//        }
//        case 2:
//        {
//            Sprite* spHp = Sprite::create("icon_hp.png");
//            spHp->setPosition(Vec2(25*3,spHp->getContentSize().height*0.5));
//            spHp->setTag(tag_playerHp3);
//            LevelScene::sharedLevelScene()->addChild(spHp,10);
//            break;
//        }
//        default:
//            break;
//    }
//}
//
////处于无敌时间时的处理函数
//void Player::strongIng(float dt){
//    strongCount++;
//    if(strongCount>=strongTime){
//        this->setVisible(true);
//        isStrong=false;
//        this->unschedule(schedule_selector(Player::strongIng));
//    }else{
//        //主角处于无敌时间时的闪烁效果
//        if(strongCount%2==0){
//            this->setVisible(false);
//        }else{
//            this->setVisible(true);
//        }
//    }
//}