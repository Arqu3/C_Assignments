#include "Enemy.h"
#include <string>
#include <algorithm>
#include "Bullet.h"

using namespace std;

static const int speed = 2;

static string fileName = "Invader.png";
static VGCImage image;

static int width;
static int height;

Enemy::Enemy(VGCVector Position, VGCRectangle Rectangle, int WDirection, float BulletCD) :
	mPosition(Position),
	mDirection(WDirection),
	mBulletCD(BulletCD),
	mIsVisible(true)
{
	mRectangle = Rectangle;
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	move();

	setRectangle();

	cdTick();

	visibilityCheck();
}

void Enemy::render()
{
	VGCVector index(0, 0);
	VGCAdjustment adjustment(0.5, 0.5);
	VGCDisplay::renderImage(image, index, mPosition, adjustment);
}

void Enemy::initialize()
{
	image = VGCDisplay::openImage(fileName, 1, 1);
}

void Enemy::finalize()
{
	VGCDisplay::closeImage(image);
}

bool Enemy::visibilityCheck()
{
	//If outside lower screen boundary, set to not alive
	if (mPosition.getY() > VGCDisplay::getHeight())
	{
		mIsVisible = false;
	}
	else
	{
		mIsVisible = true;
	}
	return mIsVisible;
}

void Enemy::setDead()
{
	mIsAlive = false;
}

bool Enemy::isAlive()
{
	return mIsAlive;
}

bool Enemy::canAddBullet()
{
	if (mBulletCD == 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

VGCVector Enemy::getPosition()
{
	return mPosition;
}

void Enemy::cdTick()
{
	//Bullet CD
	mBulletCD++;
	if (mBulletCD >= 15.0f)
	{
		mBulletCD = 0.0f;
	}
}

void Enemy::move()
{
	width = VGCDisplay::getWidth(image);
	height = VGCDisplay::getHeight(image);

	int x = mPosition.getX();
	int y = mPosition.getY();

	//Change X-direction if at the edge of screen
	if (x > VGCDisplay::getWidth() - width / 2)
	{
		mDirection = 0;
	}
	if (x < 0 + width / 2)
	{
		mDirection = 1;
	}

	if (mDirection == 0)
	{
		x -= speed;
	}
	else
	{
		x += speed;
	}
	y += speed;

	//Set position
	mPosition.setX(x);
	mPosition.setY(y);
}

void Enemy::setRectangle()
{
	width = VGCDisplay::getWidth(image);
	height = VGCDisplay::getHeight(image);

	//Set rectangle
	mRectangle.setPosition(mPosition);
	mRectangle.setHeight(height);
	mRectangle.setWidth(width);
}