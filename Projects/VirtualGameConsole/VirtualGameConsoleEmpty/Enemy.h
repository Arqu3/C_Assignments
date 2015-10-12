#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

#include "VGCVirtualGameConsole.h"
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(VGCVector Position, VGCRectangle Rectangle, int WDirection, float bulletCD);
	~Enemy();
	virtual void update();
	virtual void render();
	virtual void visibilityCheck();
	static void initialize();
	static void finalize();

	bool mIsVisible = true;
	float mBulletCD = 0.0f;
	VGCVector mPosition;

private:
	int mDirection = 1;
};

#endif