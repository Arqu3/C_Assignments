#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

#include "VGCVirtualGameConsole.h"

class Entity
{
public:
	typedef std::vector<Entity*> EntityVector;

	Entity();
	virtual ~Entity();
	virtual void update(EntityVector &entities) = 0;
	virtual void render() = 0;
	virtual bool isAlive() = 0;
	virtual VGCVector getPosition() = 0;
	virtual int getRadius() = 0;
	virtual int getDamage() = 0;
	bool mIsAlive = true;
	VGCRectangle mRectangle;

};

#endif