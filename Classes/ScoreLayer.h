#ifndef __ld__ScoreLayer__
#define __ld__ScoreLayer__

#include "cocos2d.h"
USING_NS_CC;

class ScoreLayer : public Layer
{
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(ScoreLayer);
    
private:
    //�˵���"�������˵�"�Ļص�����
    void backMenu(Ref* psend);
};

#endif /* defined(__ld__ScoreLayer__) */
