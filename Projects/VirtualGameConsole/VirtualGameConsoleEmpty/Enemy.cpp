#include "Enemy.h"

using namespace std;

static const int speed = 2;

static string fileName = "Invader.png";
static VGCImage image;

static int width;
static int height;

Enemy::Enemy(VGCVector &Position, VGCRectangle &Rectangle, int &WDirection, float BulletCD) :
	Entity(),
	mPosition(Position),
	mDirection(WDirection),
	mBulletCD(BulletCD),
	mDamage(10),
	mRadius(16)
	//mIsVisible(true)
{
	mRectangle = Rectangle;
}

Enemy::~Enemy()
{

}

void Enemy::update(EntityVector &entities)
{
	move();

	setRectangle();

	cdTick();

	addBullet(entities);

	visibilityCheck();

	if (!isAlive())
	{
		addExplosion(entities);
	}
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
	if (mPosition.getY() > VGCDisplay::getHeight() + height)
	{
		mIsAlive = false;
	}
	return mIsAlive;
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

void Enemy::addBullet(EntityVector &entites)
{
	VGCVector direction(0, 1);
	VGCRectangle rect(mPosition, 0, 0);

	if (canAddBullet())
	{
		entites.push_back(new Bullet(mPosition, rect, direction));
	}
}

VGCVector Enemy::getPosition()
{
	return mPosition;
}

int Enemy::getDamage()
{
	return mDamage;
}

int Enemy::getRadius()
{
	return mRadius;
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

void Enemy::addExplosion(EntityVector &entities)
{
	float timer = 100.0f;
	entities.push_back(new Explosion(mPosition, timer));
}