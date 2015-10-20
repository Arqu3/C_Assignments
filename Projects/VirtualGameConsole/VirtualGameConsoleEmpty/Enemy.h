#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

#include "VGCVirtualGameConsole.h"
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(VGCVector Position, VGCRectangle Rectangle, int WDirection, float bulletCD);
	~Enemy();
	void update();
	void render();
	bool visibilityCheck();
	bool canAddBullet();
	VGCVector getPosition();
	void setDead();
	bool isAlive();
	static void initialize();
	static void finalize();

private:
	float mBulletCD;
	VGCVector mPosition;
	int mDirection;
	bool mIsVisible;

	void move();
	void setRectangle();
	void cdTick();
};

#endif