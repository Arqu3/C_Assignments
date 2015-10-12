#ifndef INCLUDED_BULLET
#define INCLUDED_BULLET

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(VGCVector Position, VGCRectangle Rectangle, VGCVector Direction);
	virtual ~Bullet();
	virtual void update();
	virtual void render();
	virtual void visibilityCheck();
	static void initialize();
	static void finalize();

	virtual float clamp(float n, float lower, float upper);

private:
	VGCVector mPosition;
	VGCVector mDirection;
};

#endif

