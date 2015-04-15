#ifndef __ld__Config__
#define __ld__Config__

#include <string.h>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

extern bool soundOn;

static string MUSIC = "music/";

static string IMG = "img/";
static string IMG_BG = "img/bg/";
static string IMG_MENU = "img/menu/";
static string IMG_ABOUT = "img/about/";
static string IMG_PLAYER = "img/player/";
static string IMG_ENEMY = "img/enemy/";

static string SOUND_KEY = "soundOn";

static string STRING_FILE = "strings.plist";

static string ENEMY_CONFIG = "enemy.plist";

typedef enum {
	YELLOW,
	RED,
	BLUE
} PlanType;

typedef enum {
	PLAYER_YELLOW,
	PLAYER_PURPLE,
	ENMEY_YELLOW
} BulletType;

typedef enum {
	LOWEST,
	LOW,
	NORMAL,
	BETTER,
	BOSS
} EnemyType;

class Config : public Ref
{
public:
	~Config();
	static Config* getInstance();
	Vector<Sprite*> getEnemyArray() {return enemyArray;};
	void addEnemy(Sprite* enemy);

private:
	Vector<Sprite*> enemyArray;
	bool init();
};

#endif /* defined(__ld__Config__) */