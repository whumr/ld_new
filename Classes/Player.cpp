#include "Player.h"

static Player* player = NULL;
static int Bullet_gap = 12;
static int Bullet_y = 15;

Player* Player::getInstance()
{
	if (!player)
	{
		player = new Player();
		if(player && player->init())
		{
			player->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(player);
			player = NULL;
		}
	}
	player->initPlane();
	return player;
}

bool Player::init()
{
	_hp = 3;
	_score = 0;
	_kill = 0;
	_bullet = 3;
	_speed = 20;
	_shootDelay = 1;
	_dead = false;
	_type = DEFAULT_TYPE;
	_bulletType = BulletType::PLAYER_YELLOW;
	return true;
}

void Player::initPlane()
{
	switch (_type)
	{
	case PlanType::YELLOW:
		this->initWithSpriteFrameName("plan_yellow");
		_bulletType = BulletType::PLAYER_YELLOW;
		break;
	case PlanType::RED:
		this->initWithSpriteFrameName("plan_red");
		_bulletType = BulletType::PLAYER_YELLOW;
		break;
	case PlanType::BLUE:
		this->initWithSpriteFrameName("plan_blue");
		_bulletType = BulletType::PLAYER_PURPLE;
		break;
	default:
		break;
	}
	this->schedule(schedule_selector(Player::shoot), _shootDelay);
}

void Player::shot()
{
	_hp--;
	if (_hp <= 0)
	{
		this->die();
	}
}

void Player::die()
{
}

void Player::shoot(float time)
{
	auto position = this->getPosition();
	Bullet* bullet = Bullet::createBullet(_bulletType);
	bullet->setPosition(position + Vec2(0, Bullet_y));
	this->getParent()->addChild(bullet);
	if (_bullet >= 1)
	{
		Bullet* bullet1 = Bullet::createBullet(_bulletType);
		bullet1->setPosition(position + Vec2(Bullet_gap * 1, Bullet_y));
		Bullet* bullet2 = Bullet::createBullet(_bulletType);
		bullet2->setPosition(position + Vec2(-Bullet_gap * 1, Bullet_y));
		this->getParent()->addChild(bullet1);
		this->getParent()->addChild(bullet2);
	}
	if (_bullet >= 2)
	{
		Bullet* bullet3 = Bullet::createBullet(_bulletType);
		bullet3->setPosition(position + Vec2(Bullet_gap * 2, Bullet_y));
		Bullet* bullet4 = Bullet::createBullet(_bulletType);
		bullet4->setPosition(position + Vec2(-Bullet_gap * 2, Bullet_y));
		this->getParent()->addChild(bullet3);
		this->getParent()->addChild(bullet4);
	}
	if (_bullet >= 3)
	{
		Bullet* bullet5 = Bullet::createBullet(_bulletType);
		bullet5->setPosition(position + Vec2(Bullet_gap * 3, Bullet_y));
		Bullet* bullet6 = Bullet::createBullet(_bulletType);
		bullet6->setPosition(position + Vec2(-Bullet_gap * 3, Bullet_y));
		this->getParent()->addChild(bullet5);
		this->getParent()->addChild(bullet6);
	}
}

void Player::setType(PlanType type)
{
	_type = type;
	this->initPlane();
}

Player::~Player()
{
	player->cleanup();
	player = NULL;
}