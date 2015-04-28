#include "Skill.h"

Skill* Skill::createSkill(SkillType skillType)
{
    Skill* skill = new Skill();
	if(skill && skill->init(skillType))
    {
        skill->autorelease();
        return skill;
    }
    CC_SAFE_DELETE(skill);
    return NULL;
}

bool Skill::init(SkillType skillType)
{
	string img = IMG_PLAYER;
	ccMenuCallback callback;
	switch (skillType)
	{
	case SkillType::SKILL_THUNDER:
		{
			img += "skill2.png";
			callback = CC_CALLBACK_0(Skill::thunder, this);
			break;
		}
	case SkillType::SKILL_REINFORCE:
		{
			img += "skill1.png";
			callback = CC_CALLBACK_0(Skill::thunder, this);
			break;
		}
	default:
		return false;
	}
    MenuItemImage* skill = MenuItemImage::create(img, img, callback);
	_skillSize = skill->getContentSize();
    Menu *menu = Menu::create(skill, NULL);
    menu->setAnchorPoint(Vec2(0, 0));
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
	return true;
}

Size Skill::getSkillSize()
{
	return _skillSize;
}

void Skill::thunder()
{
	log("thunder...");
	Player::getInstance()->thunder();

	auto animationCache = AnimationCache::getInstance();
	// check if already loaded
	auto animation = animationCache->getAnimation("skill_thunder");
	if (!animation)
	{
		auto spriteFrameCache = SpriteFrameCache::getInstance();
		animation = Animation::create();
		animation->setDelayPerUnit(0.2f);
		//put frames into animation
		for (int i = 0; i < 8; i++)
		{
			animation->addSpriteFrame(spriteFrameCache->getSpriteFrameByName(String::createWithFormat("thunder_%d.png", i)->getCString()));
		}
		// put the animation into cache
		animationCache->addAnimation(animation, "skill_thunder");
	}
	auto animate = Animate::create(animation);
	Sprite* thunder = Sprite::createWithSpriteFrameName("thunder_0.png");
	thunder->setPosition(SIZE_WIDTH / 2, SIZE_HEIGHT / 2);
	thunder->runAction(RepeatForever::create(animate));
	this->getParent()->addChild(thunder);
}

void Skill::reinforce()
{
	log("reinforce...");
}