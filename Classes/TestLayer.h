#ifndef __ld__TestLayer__
#define __ld__TestLayer__

#include "Config.h"
#include "MenuLayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Effect.h"
#include "PauseLayer.h"
#include "LdMap.h"

class TestLayer : public Layer
{
    
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(TestLayer);
    
private:        
	void addEnemy(float time);
	bool TouchBegan(Touch *pTouch, Event *pEvent);
	void TouchMoved(Touch *pTouch, Event *pEvent, Vec2 min, Vec2 max);
	void doPause(Ref* psend);
	void drawHp(bool init = false);
	void drawScore();
	void update(float time);

	int _score;
	int _player_hp;
};
#endif /* defined(__ld__TestLayer__) */
