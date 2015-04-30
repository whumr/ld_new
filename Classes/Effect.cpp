#include "Effect.h"

static Effect* effect = NULL;

Effect* Effect::getInstance()
{
	if (!effect)
	{
		effect = new Effect();
		if(effect && effect->init())
		{
			effect->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(effect);
			effect = NULL;
		}		
	}
	return effect;
}

bool Effect::init()
{
	return true;
}

void Effect::enemyBoom(Node* layer, Vec2 position)
{
	ParticleSystemQuad* boom = ParticleSystemQuad::create(IMG_ENEMY + "ememy_boom.plist");
	boom->setAutoRemoveOnFinish(true);//自动释放
	boom->setPosition(position);//怪的位置		
	layer->addChild(boom);
}

void Effect::bossBoom(Node* layer, Vec2 position)
{
	auto animationCache = AnimationCache::getInstance();
	// check if already loaded
	auto animation = animationCache->getAnimation("boss_explosion");
	if (!animation)
	{
		auto spriteFrameCache = SpriteFrameCache::getInstance();
		animation = Animation::create();
		animation->setDelayPerUnit(0.1f);
		//put frames into animation
		for (int i = 1; i <= 9; i++)
		{
			animation->addSpriteFrame(spriteFrameCache->getSpriteFrameByName(String::createWithFormat("explosion_%d.png", i)->getCString()));
		}
		// put the animation into cache
		animationCache->addAnimation(animation, "boss_explosion");
	}
	Sprite* boom = Sprite::createWithSpriteFrameName("explosion_1.png");	
	boom->setPosition(position);
	layer->addChild(boom);
	boom->runAction(Sequence::create(Animate::create(animation), 
		CallFuncN::create(CC_CALLBACK_1(Effect::removeNode, this)), NULL));
}

void Effect::removeNode(Node* node)
{
	node->removeFromParentAndCleanup(true);
}

Effect::~Effect()
{
	effect = NULL;
}