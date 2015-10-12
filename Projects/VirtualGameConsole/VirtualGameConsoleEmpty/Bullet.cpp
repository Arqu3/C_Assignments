#include "Bullet.h"
#include <string>

using namespace std;

static const int speed = 6;

string fileName = "Bullet.png";
static VGCImage image;

Bullet::Bullet(VGCVector Position, VGCRectangle Rectangle, VGCVector Direction)
{
	mPosition = Position;
	mRectangle = Rectangle;
	mDirection = Direction;
}


Bullet::~Bullet()
{
}

void Bullet::update()
{
	int y = mPosition.getY();
	int x = mPosition.getX();

	//Clamp movement to speed max value, add positive/negative direction when added, not speed
	y += clamp(speed * mDirection.getY(), -speed, speed);
	x += clamp(speed * mDirection.getX(), -speed, speed);

	//Set position
	mPosition.setY(y);
	mPosition.setX(x);

	//Set rectangle
	mRectangle.setPosition(mPosition);
	mRectangle.setWidth(VGCDisplay::getWidth(image));
	mRectangle.setHeight(VGCDisplay::getHeight(image));

	//Check visibility
	visibilityCheck();
}

void Bullet::render()
{
	VGCVector index(0, 0);
	VGCAdjustment adjustment(0.5, 0.5);
	VGCDisplay::renderImage(image, index, mPosition, adjustment);
}

void Bullet::initialize()
{
	image = VGCDisplay::openImage(fileName, 1, 1);
}

void Bullet::finalize()
{
	VGCDisplay::closeImage(image);
}

void Bullet::visibilityCheck()
{
	//Set to not alive when outside screen
	if (mPosition.getX() > VGCDisplay::getWidth() || mPosition.getX() < 0
		|| mPosition.getY() > VGCDisplay::getHeight() || mPosition.getY() < 0)
	{
		mIsAlive = false;
	}
}

float Bullet::clamp(float n, float lower, float upper)
{
	return std::fmaxf(lower, std::fminf(n, upper));
}