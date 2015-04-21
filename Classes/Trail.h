#ifndef __ld__Trail__
#define __ld__Trail__

#include "Config.h"
#include "CircleBy.h"

class Trail : public Ref
{
public:
	static void moveDown(Sprite* sprite, float velocity);
	static void circleFromLeftTop(Sprite* sprite, float time);
	static void circleFromRightTop(Sprite* sprite, float time);
};

#endif /* defined(__ld__Trail__) */