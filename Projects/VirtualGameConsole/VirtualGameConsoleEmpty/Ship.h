#ifndef INCLUDED_SHIP
#define INCLUDED_SHIP

#include "Entity.h"
#include "VGCVirtualGameConsole.h"
#include "Bullet.h"


class Ship : public Entity
{
public:
	Ship();
	virtual ~Ship();
	virtual void update();
	virtual void render();
	static void initialize();
	static void finalize();
	bool isAlive();

	typedef std::vector<Entity*> EntityVector;
	EntityVector Projectiles;

	int mHealth = 100;
	int mScore = 0;
	float mBulletCD = 0.0f;

private:
	VGCVector mPosition;

	virtual void addBullet();
	virtual void updateBullet();
	virtual void move();
	virtual void setRectangle();
	virtual void renderBullet();
	virtual void renderText();
};

#endif