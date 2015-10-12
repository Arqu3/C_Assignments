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
	virtual bool visibilityCheck();
	static void initialize();
	static void finalize();

	float mBulletCD;
	VGCVector mPosition;

private:
	int mDirection;
	bool mIsVisible;
};

#endif