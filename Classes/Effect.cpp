#include "Effect.h"

ParticleSystemQuad* Effect::enemyBoom(Vec2 position)
{
	ParticleSystemQuad* boom = ParticleSystemQuad::create(IMG_ENEMY + "ememy_boom.plist");
    boom->setPosition(position);//怪的位置
    boom->setAutoRemoveOnFinish(true);//自动释放
	return boom;
}
