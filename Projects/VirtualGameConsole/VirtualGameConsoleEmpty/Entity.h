#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

#include "VGCVirtualGameConsole.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual void update() = 0;
	virtual void render() = 0;
	bool mIsAlive = true;
	VGCRectangle mRectangle;

	//typedef std::vector<Bullet&> BulletVector;
	//BulletVector mBullets;
};

#endif