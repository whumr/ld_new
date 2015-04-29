#ifndef __ld__Skill__
#define __ld__Skill__

#include "Config.h"
#include "Player.h"
#include "Enemy.h"

class Skill : public Node
{
public:
    static Skill* createSkill(SkillType skillType);//ʵ������
	Size getSkillSize();

private:
	Size _skillSize;
	Vector<Sprite*> _thunders;

    bool init(SkillType skillType);//��ʼ������

	void thunder();
	void thundering(float time);
	void thunderEnd(Node* thunder);
	void reinforce();
};

#endif /* defined(__ld__Skill__) */
