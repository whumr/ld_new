#include "Gem.h"

Gem* Gem::createGem(GemType gemType){
    Gem* gem = new Gem();
    if(gem && gem->init(gemType)){
        gem->autorelease();
        return gem;
    }
    CC_SAFE_DELETE(gem);
    return NULL;
}

bool Gem::init(GemType gemType)
{
	_type = gemType;
	_dead = false;
	string key = "";
	switch (gemType)
	{
	case GemType::HP:
		{
			key = "gem_hp";
			break;
		}
	case GemType::BULLET:
		{
			key = "gem_bullet";
			break;
		}
	case GemType::MISSILE:
		{
			key = "gem_missile";
			break;
		}
	case GemType::THUNDER:
		{
			key = "gem_thunder";
			break;
		}
	default:
		return false;
	}
	this->initWithSpriteFrameName(key);
	//position
	auto size = Director::getInstance()->getWinSize();
	auto contentSize = getContentSize();
	float x = CCRANDOM_0_1() * size.width;
	x = x < contentSize.width / 2 ? contentSize.width / 2 : 
		(x > size.width - contentSize.width / 2 ? size.width - contentSize.width / 2 : x);
	float y = size.height + contentSize.height / 2;
	setPosition(x, y);
	//move
	Trail::moveRandom(this, 150, 20);
    this->scheduleUpdate();
	return true;
}

void Gem::update(float dt)
{
	Player* player = Player::getInstance();
	if(!this->_dead && player->getBoundingBox().intersectsRect(this->getBoundingBox()))
    {
		if (!player->getDead())
		{
			player->addGem(_type);			
			_dead = true;
			this->removeFromParentAndCleanup(true);
		}
    }
}