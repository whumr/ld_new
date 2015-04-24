#ifndef __ld__Gem__
#define __ld__Gem__

#include "Config.h"
#include "Player.h"
#include "Trail.h"

class Gem : public Sprite
{
public:
    static Gem* createGem(GemType gemType);//ÊµÀýº¯Êý
	CC_SYNTHESIZE(GemType, _type, Type);
	CC_SYNTHESIZE(bool, _dead, Dead);
    
private:
	bool init(GemType gemType);
    void update(float dt);
};

#endif /* defined(__ld__Gem__) */
