#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

#include "VGCVirtualGameConsole.h"
#include "Entity.h"
#include "Bullet.h"
#include "Explosion.h"
#include <string>
#include <algorithm>

class Enemy : public Entity
{
public:
	Enemy(VGCVector &Position, VGCRectangle &Rectangle, int &WDirection, float bulletCD);
	~Enemy();
	void update(EntityVector &entities);
	void render();
	VGCVector getPosition();
	void setDead();
	bool isAlive();
	int getDamage();
	int getRadius();
	VGCVector getPosition();
	static void initialize();
	static void finalize();

private:
	float mBulletCD;
	VGCVector mPosition;
	int mDirection;
	int mDamage;
	int mRadius;
	//bool mIsVisible;

	bool visibilityCheck();
	bool canAddBullet();
	void move();
	void setRectangle();
	void cdTick();
	void addBullet(EntityVector &entities);
	void addExplosion(EntityVector &entities);
};

#endif