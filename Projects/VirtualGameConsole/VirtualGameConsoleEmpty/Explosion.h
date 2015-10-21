#ifndef INCLUDED_EXPLOSION
#define INCLUDED_EXPLOSION

#include "VGCVirtualGameConsole.h"
#include <string>
#include "Entity.h"

class Explosion : public Entity
{
public:
	Explosion(VGCVector &Position, float Timer);
	~Explosion();

	static void initialize();
	static void finalize();

	void render();
	void update(EntityVector &entities);
	bool isAlive();
	int getDamage();
	int getRadius();
	VGCVector getPosition();

private:
	VGCVector mPosition;
	float mTimer;
	int mDamage;
	int mRadius;
};

#endif