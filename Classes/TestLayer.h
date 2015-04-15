#ifndef __ld__TestLayer__
#define __ld__TestLayer__

#include "Config.h"

class TestLayer : public Layer
{
    
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(TestLayer);
    
private:
    void backMenu(Ref* psend);    
	void addEnemy(float time);
	bool TouchBegan(Touch *pTouch, Event *pEvent);
	void TouchMoved(Touch *pTouch, Event *pEvent, Vec2 min, Vec2 max);

};
#endif /* defined(__ld__TestLayer__) */
