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
	Player* player = Player::getInstance();
	if (!player->getThundering())
	{
		player->thunder();
		auto animationCache = AnimationCache::getInstance();
		// check if already loaded
		auto animation = animationCache->getAnimation("skill_thunder");
		if (!animation)
		{
			auto spriteFrameCache = SpriteFrameCache::getInstance();
			animation = Animation::create();
			animation->setDelayPerUnit(0.1f);
			//put frames into animation
			for (int i = 0; i < 8; i++)
			{
				animation->addSpriteFrame(spriteFrameCache->getSpriteFrameByName(String::createWithFormat("thunder_%d.png", i)->getCString()));
			}
			// put the animation into cache
			animationCache->addAnimation(animation, "skill_thunder");
		}
		float x = (SIZE_WIDTH - 100) / 6;
		float y = (SIZE_HEIGHT - 80) / 8;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Sprite* thunder = Sprite::createWithSpriteFrameName("thunder_0.png");
				thunder->setPosition(50 + x * (i * 2 + 1), 40 + y * (j * 2 + 1));
				thunder->setRotation(15);
				this->getParent()->addChild(thunder);
				_thunders.pushBack(thunder);
				thunder->runAction(Sequence::create(Repeat::create(Animate::create(animation), 10), 
					CallFuncN::create(CC_CALLBACK_1(Skill::thunderEnd, this)), NULL));
			}
		}
		this->getParent()->schedule(CC_CALLBACK_1(Skill::thundering, this), 1, "thudering");
	}	
}

void Skill::thunderEnd(Node* thunder)
{	
	_thunders.eraseObject((Sprite*)thunder);
	thunder->removeFromParentAndCleanup(true);
	if (_thunders.empty())
	{
		log("thunderEnd...");
		Player::getInstance()->setThundering(false);
	}
}

void Skill::thundering(float time)
{
	if (Player::getInstance()->getThundering())
	{
		Vector<Sprite*> enemyArray = Config::getInstance()->getEnemyArray();
		for (int i = 0; i < enemyArray.size(); i++) 
		{
			((Enemy*)(enemyArray.at(i)))->shot();
		}
	}
	else
	{
		this->getParent()->unschedule("thudering");
	}
}

void Skill::reinforce()
{
	log("reinforce...");
}