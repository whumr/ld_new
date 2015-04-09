#ifndef __ld__TestLayer__
#define __ld__TestLayer__

#include "Config.h"
#include "cocos2d.h"
USING_NS_CC;

class TestLayer : public Layer
{
    
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(TestLayer);
    
private:
    void backMenu(Ref* psend);    
};
#endif /* defined(__ld__TestLayer__) */
