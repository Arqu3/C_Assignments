#ifndef INCLUDED_BULLET
#define INCLUDED_BULLET

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(VGCVector Position, VGCRectangle Rectangle, VGCVector Direction);
	~Bullet();
	void update();
	void render();
	void visibilityCheck();
	static void initialize();
	static void finalize();


private:
	VGCVector mPosition;
	VGCVector mDirection;

	virtual float clamp(float n, float lower, float upper);
};

#endif

