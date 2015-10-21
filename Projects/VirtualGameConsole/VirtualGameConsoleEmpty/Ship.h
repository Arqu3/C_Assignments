#ifndef INCLUDED_SHIP
#define INCLUDED_SHIP

#include "Entity.h"
#include "VGCVirtualGameConsole.h"
#include "Bullet.h"
#include <string>
#include <algorithm>


class Ship : public Entity
{
public:
	Ship(VGCVector &Position);
	 ~Ship();
	void update(EntityVector &entities);
	void render();
	static void initialize();
	static void finalize();
	bool isAlive();
	int getDamage();
	int getRadius();
	VGCVector getPosition();
	void takeDMG(int dmg);
	void addScore();

private:
	VGCVector mPosition;
	int mDamage;
	int mRadius;
	float mBulletCD;
	int mHealth;
	int mScore;
	//EntityVector mEntities;

	void addBullet(EntityVector &entities);
	void move();
	void setRectangle();
	void renderText();
};

#endif