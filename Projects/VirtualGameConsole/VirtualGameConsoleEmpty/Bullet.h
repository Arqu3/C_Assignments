#ifndef INCLUDED_BULLET
#define INCLUDED_BULLET

#include "Entity.h"
#include <string>

class Bullet : public Entity
{
public:
	Bullet(VGCVector &Position, VGCRectangle &Rectangle, VGCVector &Direction);
	~Bullet();
	void update(EntityVector &entities);
	void render();
	bool isAlive();
	int getDamage();
	int getRadius();
	VGCVector getPosition();
	static void initialize();
	static void finalize();


private:
	VGCVector mPosition;
	VGCVector mDirection;
	int mDamage;
	int mRadius;
	void visibilityCheck();

	virtual float clamp(float n, float lower, float upper);
};

#endif

