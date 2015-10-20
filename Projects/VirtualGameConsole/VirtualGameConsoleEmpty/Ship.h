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
	void takeDMG(int dmg);
	void addScore();

	typedef std::vector<Entity*> EntityVector;
	EntityVector Projectiles;

private:
	VGCVector mPosition;
	float mBulletCD;
	int mHealth;
	int mScore;

	void addBullet();
	void updateBullet();
	void move();
	void setRectangle();
	void renderBullet();
	void renderText();
};

#endif