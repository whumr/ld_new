#ifndef __ld__Skill__
#define __ld__Skill__

#include "Config.h"
#include "Player.h"
#include "Enemy.h"

class Skill : public Node
{
public:
    static Skill* createSkill(SkillType skillType);//实例函数
	Size getSkillSize();

private:
	Size _skillSize;
	Vector<Sprite*> _thunders;

    bool init(SkillType skillType);//初始化函数

	void thunder();
	void thundering(float time);
	void thunderEnd(Node* thunder);
	void reinforce();
};

#endif /* defined(__ld__Skill__) */
