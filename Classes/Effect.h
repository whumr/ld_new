#ifndef __ld__Effect__
#define __ld__Effect__

#include "Config.h"

class Effect : public Ref
{
public:
	static Effect* getInstance();

	~Effect();
	void enemyBoom(Node* layer, Vec2 position);
	void bossBoom(Node* layer, Vec2 position);
private:
	bool init();
	void removeNode(Node* node);
};

#endif /* defined(__ld__Effect__) */