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
    //�˵���"�������˵�"�Ļص�����
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
