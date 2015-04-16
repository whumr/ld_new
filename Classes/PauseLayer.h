#ifndef __ld__PauseLayer__
#define __ld__PauseLayer__

#include "Config.h"
#include "TestLayer.h"

class PauseLayer : public LayerColor {
    
public:
    virtual bool init();
    CREATE_FUNC(PauseLayer);

private:
	bool TouchBegan(Touch* touch, Event* event);
	void doResume(Ref* pSender);
	void doBack(Ref* pSender);

};

#endif /* defined(__ld__PauseLayer__) */