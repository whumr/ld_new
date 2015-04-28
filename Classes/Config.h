#ifndef __ld__Config__
#define __ld__Config__

#include <string.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

extern bool soundOn;
extern int level;
extern float SIZE_WIDTH;
extern float SIZE_HEIGHT;

static int MAX_HP = 3;
static int MAX_BULLET = 3;
static int MAX_THUNDER = 3;

static string DEFAULT_FONT = "fonts/Marker Felt.ttf";

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

typedef enum {
	HP,
	BULLET,
	MISSILE,
	THUNDER
} GemType;

typedef enum{
	TAG_SCORE = 100,
	TAG_HP_1,
	TAG_HP_2,
	TAG_HP_3,
	TAG_SKILL_1,
	TAG_SKILL_2,
	TAG_SKILL_3
} LayerTag;

typedef enum{
	SKILL_THUNDER,
	SKILL_REINFORCE
} SkillType;

class Config : public Ref
{
public:
	~Config();
	static Config* getInstance();
	Vector<Sprite*> getEnemyArray() {return enemyArray;};
	//不能由外部getEnemyArray之后使用push操作
	void addEnemy(Sprite* enemy);
	void removeEnemy(Sprite* enemy);
	void addBullet(Sprite* bullet);
	void removeBullet(Sprite* bullet);
	void setMap(Layer* map);
	void removeAll();

private:
	Vector<Sprite*> enemyArray;
	Vector<Sprite*> bulletArray;
	Layer* _map;
	bool init();
};

#endif /* defined(__ld__Config__) */