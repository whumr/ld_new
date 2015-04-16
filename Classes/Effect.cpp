#include "Effect.h"

//static ParticleBatchNode* enemyBoomBatch = NULL;

ParticleSystemQuad* Effect::enemyBoom(Vec2 position)
{
	ParticleSystemQuad* boom = ParticleSystemQuad::create(IMG_ENEMY + "ememy_boom.plist");
	boom->setAutoRemoveOnFinish(true);//�Զ��ͷ�
	boom->setPosition(position);//�ֵ�λ��		
	return boom;
}

//ParticleBatchNode* Effect::getEnemyBoomBatch(bool init)
//{
//	if (!enemyBoomBatch)
//	{
//		ParticleSystemQuad* boom = ParticleSystemQuad::create(IMG_ENEMY + "ememy_boom.plist");
//		enemyBoomBatch = ParticleBatchNode::createWithTexture(boom->getTexture());
//	}
//	else if (init)
//	{
//		enemyBoomBatch->removeAllChildrenWithCleanup(true);
//	}
//	return enemyBoomBatch;
//}