#include "Bullet.h"

Bullet* Bullet::createBullet(BulletType type)
{
	Bullet* bullet = new Bullet();
	bullet->setType(type);
    if(bullet && bullet->init()){
        bullet->autorelease();
		Config::getInstance()->addBullet(bullet);
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return NULL;
}

bool Bullet::init()
{
	_speed = Vec2(0, 6);
	_enemy = false;
	_dead = false;
	switch (_type)
	{
	case BulletType::PLAYER_YELLOW:
		this->initWithSpriteFrameName("bullet_player_yellow");
		break;
	case BulletType::PLAYER_PURPLE:
		this->initWithSpriteFrameName("bullet_player_purple");
		break;
	case BulletType::ENMEY_YELLOW:
		_speed = Vec2(0, -5);
		_enemy = true;
		this->initWithSpriteFrameName("bullet_enemy_yellow");
		break;
	default:
		break;
	}
	this->scheduleUpdate();
	return true;
}

void Bullet::update(float time)
{    
	if (!_dead) 
	{
		this->setPosition(this->getPosition() + _speed);
		auto size = Director::getInstance()->getWinSize();
		if(this->getPositionY() < -this->getContentSize().height || this->getPositionY() > size.height + this->getContentSize().height 
			|| this->getPositionX() < -this->getContentSize().width || this->getPositionX() > size.width + this->getContentSize().width)
		{
			Config::getInstance()->removeBullet(this);
			this->removeFromParentAndCleanup(true);
			return;
		}
    
		//处理子弹击中
		if (_enemy)
		{
			this->checkPlayerShot();
		}
		else
		{
			this->checkEnemyShot();
		}
	}	
}

void Bullet::checkEnemyShot()
{
	Vector<Sprite*> array = Config::getInstance()->getEnemyArray();
	for (int i = 0; i < array.size(); i++) 
	{
		Enemy* enemy = (Enemy*)array.at(i);
		if(!this->_dead && enemy->getBoundingBox().intersectsRect(this->getBoundingBox()))
        {
			if (!enemy->getDead())
			{
				enemy->shot();
				this->die();
			}
        }
    }
}

void Bullet::checkPlayerShot()
{
	Player* player = Player::getInstance();
	if(!this->_dead && player->getBoundingBox().intersectsRect(this->getBoundingBox()))
    {
		if (!player->getDead())
		{
			player->shot();
			this->die();
		}
    }
}

void Bullet::die()
{
	_dead = true;
	Config::getInstance()->removeBullet(this);
	this->removeFromParentAndCleanup(true);
}