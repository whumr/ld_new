#ifndef __ld__GameLayer__
#define __ld__GameLayer__

//#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class GameLayer : public Layer
{
public:
    static Scene* scene();
    
    //获取当前HWorld的静态实例
    static GameLayer * sharedLevelScene();
    
    virtual bool init();
    CREATE_FUNC(GameLayer);
    
    virtual ~GameLayer();//析构函数
    
    void TouchMoved(Touch *pTouch, Event *pEvent);
    bool TouchBegan(Touch *pTouch, Event *pEvent);
    //void registerWithTouchDispatcher();
    
    bool isPlayerChange;
    //NewPlayer* getPlayer();
    void resetPlayer(float f);
    void setPlayer(int i);
    
    int BulletDelayCount;
    
    //Vector<NewEnemy*> arrayEnemy;//存放敌怪的数组
    
    void doPause(Ref* psend);
    void winGame();
    void lostGame();
    void autoCreateBullet(float f);
    void autoCreateEnemy(float f);
    void setEnemy(float f);
    void autoCreateGems(float f);
    void putGems();
    void removeSupplyPlane();
    //Vector<NewEnemy*> getArrayForEnemy();//获取存放敌怪的数组
    
    void backMenu(Ref* psend);
    void addPlaneProperty();
    
    int enemyType;
    int enemyType1TimeCount;
    int enemyType2TimeCount;
    int enemyType3TimeCount;
    int enemyType4TimeCount;
    int enemyType5TimeCount;
    int enemyType6TimeCount;
    int allTimeCount;
    int creatEnemyInterval;
    bool passCreatEnemy;
    
    const char* bulletType1;
    const char* bulletType2;
    
    SpriteBatchNode *bulletBatchNode;
    SpriteBatchNode *enemyBatchNode;
    SpriteBatchNode *playersBatchNode;
    
    bool isGetNewRecord;
    
};


#endif /* defined(__ld__GameLayer__) */
