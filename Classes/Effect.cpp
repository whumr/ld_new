#include "Effect.h"

ParticleSystemQuad* Effect::enemyBoom(Vec2 position)
{
	ParticleSystemQuad* boom = ParticleSystemQuad::create(IMG_ENEMY + "ememy_boom.plist");
    boom->setPosition(position);//�ֵ�λ��
    boom->setAutoRemoveOnFinish(true);//�Զ��ͷ�
	return boom;
}
