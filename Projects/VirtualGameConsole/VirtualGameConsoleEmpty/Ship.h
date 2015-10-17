#ifndef INCLUDED_SHIP
#define INCLUDED_SHIP

#include "Entity.h"
#include "VGCVirtualGameConsole.h"
#include "Bullet.h"


class Ship : public Entity
{
public:
	Ship();
	 ~Ship();
	void update();
	void render();
	static void initialize();
	static void finalize();
	bool isAlive();

	typedef std::vector<Entity*> EntityVector;
	EntityVector Projectiles;

	int mHealth;
	int mScore;
	float mBulletCD;

private:
	VGCVector mPosition;

	void addBullet();
	void updateBullet();
	void move();
	void setRectangle();
	void renderBullet();
	void renderText();
};

#endif