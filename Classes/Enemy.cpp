#include "Enemy.h"

Enemy* Enemy::createEnemy(EnemyType type)
{
    Enemy* enemy = new Enemy();
	enemy->setType(type);
    if(enemy && enemy->init())
	{
		enemy->autorelease();
		Config::getInstance()->addEnemy(enemy);
		return enemy;
    }
	else
	{
		CC_SAFE_DELETE(enemy);
		return NULL;
	}    
}

bool Enemy::init()
{	
	string key = "";
	switch (_type)
	{
	case EnemyType::LOWEST:
		key = "lowest";
		break;
	case EnemyType::LOW:
		key = "low";
		break;
	case EnemyType::NORMAL:
		key = "normal";
		break;
	case EnemyType::BETTER:
		key = "better";
		break;
	case EnemyType::BOSS:
		key = "boss";
		break;
	default:
		return false;
	}
	auto conf = Configuration::getInstance();
	const char* keys = key.c_str();
	this->initWithSpriteFrameName(conf->getValue(String::createWithFormat("%s.img", keys)->getCString()).asString());
	_hp = conf->getValue(String::createWithFormat("%s.hp", keys)->getCString()).asInt();
	_score = conf->getValue(String::createWithFormat("%s.score", keys)->getCString()).asInt();
	_speed = conf->getValue(String::createWithFormat("%s.speed", keys)->getCString()).asInt();
	_shootDelay = conf->getValue(String::createWithFormat("%s.shootDelay", keys)->getCString()).asInt();
	_bulletType = BulletType::ENMEY_YELLOW;
	_dead = false;
	this->toBattle();
	this->scheduleUpdate();
	this->schedule(schedule_selector(Enemy::shoot), _shootDelay);	
	return true;
}

void Enemy::toBattle()
{
	//position
	auto size = Director::getInstance()->getWinSize();
	auto contentSize = getContentSize();
	float x = CCRANDOM_0_1() * size.width;
	x = x < contentSize.width / 2 ? contentSize.width / 2 : 
		(x > size.width - contentSize.width / 2 ? size.width - contentSize.width / 2 : x);
	float y = size.height + contentSize.height;
	//run action
	switch (_type)
	{
	case EnemyType::LOWEST:
		{
			//飞行在update里面设定
			setPosition(x, y);
			break;
		}
		
	case EnemyType::LOW:
		{
			setPosition(x, y);
			//CardinalSplineTo::create()PointArray
			ccBezierConfig bezier; // 创建贝塞尔曲线
            bezier.controlPoint_1 = Vec2(0, size.height + contentSize.height / 2); // 起始点
            bezier.controlPoint_2 = Vec2(size.width / 2, size.height / 2); //控制点
            bezier.endPosition = Vec2(-contentSize.width, size.height / 2); // 结束位置
            this->runAction(BezierTo::create(4, bezier));
			break;
		}		
	case EnemyType::NORMAL:
		break;
	case EnemyType::BETTER:
		break;
	case EnemyType::BOSS:
		break;
	}
}

void Enemy::shoot(float time)
{
	auto position = this->getPosition();
	switch (_type)
	{
	case EnemyType::LOWEST:		
		{
		Bullet* bullet = Bullet::createBullet(_bulletType);
		bullet->setPosition(position + Vec2(0, -15));
		this->getParent()->addChild(bullet);
		break;
		}
	case EnemyType::LOW:
		{
		Bullet* bullet = Bullet::createBullet(_bulletType);
		bullet->setPosition(position + Vec2(0, -15));
		this->getParent()->addChild(bullet);
		break;
		}
	case EnemyType::NORMAL:
		break;
	case EnemyType::BETTER:
		break;
	case EnemyType::BOSS:
		break;
	default:
		break;
	}
}

void Enemy::shot()
{
	if (!_dead)
	{
		_hp -= 1;
		if (_hp <= 0)
		{
			this->enemyDead();
		}
	}
}

void Enemy::enemyDead()
{
	//音效
	if (soundOn)
	{
		if (_type == EnemyType::BOSS)
		{
			SimpleAudioEngine::getInstance()->playEffect((MUSIC + "effect_bigBoom.wav").c_str());
		}
		else
		{
			SimpleAudioEngine::getInstance()->playEffect((MUSIC + "effect_boom.mp3").c_str());
		}
	}	
	_dead = true;
	//动画效果
	this->getParent()->addChild(Effect::enemyBoom(this->getPosition()));	
	Player* player = Player::getInstance();
	player->setScore(player->getScore() + _score);
	Config::getInstance()->removeEnemy(this);
	this->removeFromParentAndCleanup(true);
}

void Enemy::update(float time)
{
	if (!_dead)
	{
		switch (_type)
		{
		case EnemyType::LOWEST:		
			this->setPosition(this->getPosition() - Vec2(0, _speed));			
			break;
		case EnemyType::LOW:
			break;
		case EnemyType::NORMAL:
			break;
		case EnemyType::BETTER:
			break;
		case EnemyType::BOSS:
			break;
		}
	}	
	auto size = this->getContentSize();
	auto position = this->getPosition();
	if (position.y < -size.height / 2 || position.x < -size.width / 2 
		|| position.x > Director::getInstance()->getWinSize().width + size.width / 2)
	{
		Config::getInstance()->removeEnemy(this);
		this->removeFromParentAndCleanup(true);
	}
}