#ifndef __ld__Skill__
#define __ld__Skill__

#include "Config.h"
#include "Player.h"

class Skill : public Node
{
public:
    static Skill* createSkill(SkillType skillType);//ʵ������
	Size getSkillSize();

private:
	Size _skillSize;

    bool init(SkillType skillType);//��ʼ������

	void thunder();
	void reinforce();
};

#endif /* defined(__ld__Skill__) */
