#ifndef __ld__Effect__
#define __ld__Effect__

#include <string.h>
#include "Config.h"

class Effect : public Ref
{
public:
	static ParticleSystemQuad* enemyBoom(Vec2 position);
	//static ParticleBatchNode* getEnemyBoomBatch(bool init = false);
};

#endif /* defined(__ld__Effect__) */