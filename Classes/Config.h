#ifndef __ld__Config__
#define __ld__Config__

#include <string>
#include "Enemy.h"
#include "Bullet.h"

using namespace std;

extern bool soundOn;

static string MUSIC = "music/";

static string IMG = "img/";
static string IMG_BG = "img/bg/";
static string IMG_MENU = "img/menu/";
static string IMG_ABOUT = "img/about/";
static string IMG_PLAYER = "img/player/";

static string SOUND_KEY = "soundOn";

static string STRING_FILE = "strings.plist";

static string ENEMY_CONFIG = "enemy.plist";

class Config : public Ref
{
public:
	~Config();
	static Vector<Enemy*> getEnemyArray(bool clear = false);
	static Vector<Bullet*> getBulletArray(bool clear = false);
	

private:	
	static Vector<Enemy*> enemyArray;
	static Vector<Bullet*> bulletArray;
}

#endif /* defined(__ld__Config__) */