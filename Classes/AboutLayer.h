#ifndef __ld__AboutLayer__
#define __ld__AboutLayer__


#include "cocos2d.h"
USING_NS_CC;

class AboutLayer : public Layer
{
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(AboutLayer);
    
private:
    //菜单项"返回主菜单"的回调函数
    void backMenu(Ref* psend);
    
    void a();
    void b();
    void c();
    void d();
    void e();
    void f();
    void remove();

};
#endif /* defined(__ld__AboutLayer__) */
