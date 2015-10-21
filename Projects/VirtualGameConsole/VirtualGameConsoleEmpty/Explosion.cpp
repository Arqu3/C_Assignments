#include "Explosion.h"

using namespace std;

static VGCImage image;
static string fileName = "Explosion.png";

Explosion::Explosion(VGCVector &Position, float Timer) :
	mPosition(Position),
	mTimer(Timer),
	mDamage(0),
	mRadius(16)
{
}

Explosion::~Explosion()
{
}

void Explosion::initialize()
{
	image = VGCDisplay::openImage(fileName, 1, 1);
}

void Explosion::finalize()
{
	VGCDisplay::closeImage(image);
}

void Explosion::update(EntityVector &entities)
{
	mTimer--;
	if (mTimer <= 0)
	{
		mIsAlive = false;
	}
}

void Explosion::render()
{
	VGCVector index(0, 0);
	VGCAdjustment adjustment(0.5, 0.5);
	VGCDisplay::renderImage(image, index, mPosition, adjustment);
}

bool Explosion::isAlive()
{
	return mIsAlive;
}

int Explosion::getDamage()
{
	return mDamage;
}

int Explosion::getRadius()
{
	return mRadius;
}

VGCVector Explosion::getPosition()
{
	return mPosition;
}