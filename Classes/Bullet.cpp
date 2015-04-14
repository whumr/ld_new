#include "Bullet.h"

Bullet* Bullet::createBullet(BulletType type)
{
	Bullet* bullet = new Bullet();
	bullet->setType(type);
    if(bullet && bullet->init()){
        bullet->autorelease();
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return NULL;
}

bool Bullet::init()
{
	_speed = Vec2(0, 3);
	_enemy = false;
	switch (_type)
	{
	case BulletType::PLAYER_YELLOW:
		this->initWithSpriteFrameName("bullet_player_yellow");
		break;
	case BulletType::PLAYER_PURPLE:
		this->initWithSpriteFrameName("bullet_player_purple");
		break;
	case BulletType::ENMEY_YELLOW:
		_speed = Vec2(0, -3);
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
	this->setPosition(this->getPosition() + _speed);
    auto size = Director::getInstance()->getWinSize();
    if(this->getPositionY() < -this->getContentSize().height || this->getPositionY() > size.height + this->getContentSize().height 
		|| this->getPositionX() < -this->getContentSize().width || this->getPositionX() > size.width + this->getContentSize().width)
    {
        this->removeFromParentAndCleanup(true);
        return;
    }
    
    //处理子弹击中
	switch (_type)
	{
	case BulletType::PLAYER_YELLOW:
	case BulletType::PLAYER_PURPLE:
		this->checkEnemyShot();
		break;
	case BulletType::ENMEY_YELLOW:
		this->checkPlayerShot();
		break;
	default:
		break;
	}	
}

void Bullet::checkEnemyShot()
{
	Vector<Sprite*> array = Config::getInstance()->getEnemyArray();
	for (int i = 0; i < array.size(); i++) {
		Enemy* enemy = (Enemy*)array.at(i);
        if(enemy->getBoundingBox().intersectsRect(this->getBoundingBox()))
        {
			if (!enemy->getDead())
			{
				enemy->shot();
				this->removeFromParentAndCleanup(true);
			}			
        }
    }
}

void Bullet::checkPlayerShot()
{
	Player* player = Player::getInstance();
	if(player->getBoundingBox().intersectsRect(this->getBoundingBox()))
    {
		if (!player->getDead())
		{
			player->shot();
			this->removeFromParentAndCleanup(true);
		}
    }
}

//Bullet* Bullet::createBullet(const char* _fileName,float _speed,Point _position,int _type)
//{
//    Bullet* bullet = new Bullet();
//    if(bullet && bullet->initWithSpriteFrameName(_fileName)){
//        bullet->autorelease();
//        bullet->bulletInit(_speed,_position,_type);
//        return bullet;
//    }
//    CC_SAFE_DELETE(bullet);
//    return NULL;
//}
//
//void Bullet::bulletInit(float _speed,Point _position,int _type)
//{
//    speed = _speed;
//    bulletType = _type;
//    this->setPosition(_position);
//    
//    rotation += 180;
//    rotation *=-1;
//    
//    this->scheduleUpdate();
//}
//
////子弹逻辑
