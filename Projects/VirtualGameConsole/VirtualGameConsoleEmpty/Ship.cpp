#include "Ship.h"
#include <string>
#include <algorithm>

using namespace std;

static int speed = 5;

static int height = 32;
static int width = 32;
static string fileName = "Ship.png";
static VGCImage image;

//Text output
const VGCColor textColor(255, 255, 255, 255);
//Score text
const VGCVector scoreTPosition(600, 0);
const VGCAdjustment scoreTAdjustment(1.0, 0.0);
//Health text
const VGCVector healthTPosition(0, 0);
const VGCAdjustment healthTAdjustment(0.0, 0.0);

Ship::Ship() :
	mPosition(VGCDisplay::getWidth() / 2, VGCDisplay::getHeight() / 2),
	mHealth(100),
	mScore(0),
	mBulletCD(0.0f)
{
}


Ship::~Ship()
{
}

void Ship::update()
{
	move();

	setRectangle();

	//Set shoot timer
	mBulletCD++;
	if (mBulletCD >= 12.5f)
	{
		mBulletCD = 0.0f;
	}

	//Add bullets
	if (VGCKeyboard::isPressed(VGCKey::SPACE_KEY) && mBulletCD == 0.0f)
	{
		addBullet();
	}

	//Update bullets
	updateBullet();

	isAlive();
}

bool Ship::isAlive()
{
	if (mHealth > 0)
	{
		mIsAlive = true;
	}
	else
	{
		mIsAlive = false;
	}

	return mIsAlive;
}

void Ship::move()
{
	//Set movement restrictions
	const int minX = width / 2;
	const int minY = height / 2;
	const int maxX = VGCDisplay::getWidth() - width / 2;
	const int maxY = VGCDisplay::getHeight() - height / 2;

	//Get position
	int x = mPosition.getX();
	int y = mPosition.getY();

	//Input & movement restrictions
	if (VGCKeyboard::isPressed(VGCKey::D_KEY))
	{
		x += speed;
		if (x > maxX)
		{
			x = maxX;
		}
	}
	if (VGCKeyboard::isPressed(VGCKey::A_KEY))
	{
		x -= speed;
		if (x < minX)
		{
			x = minX;
		}
	}
	if (VGCKeyboard::isPressed(VGCKey::W_KEY))
	{
		y -= speed;
		if (y < minY)
		{
			y = minY;
		}
	}
	if (VGCKeyboard::isPressed(VGCKey::S_KEY))
	{
		y += speed;
		if (y > maxY)
		{
			y = maxY;
		}
	}
	//Set position
	mPosition.setX(x);
	mPosition.setY(y);
}

void Ship::setRectangle()
{
	//Set rectangle
	mRectangle.setPosition(mPosition);
	mRectangle.setHeight(height);
	mRectangle.setWidth(width);
}

void Ship::addBullet()
{
	//Middle
	//mBullets.push_back(Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(0, -1)));
	Projectiles.push_back(new Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(0, -1)));
	
	//Right
	//mBullets.push_back(Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(1, -1)));
	Projectiles.push_back(new Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(1, -1)));
	
	//Left
	//mBullets.push_back(Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(-1, -1)));
	Projectiles.push_back(new Bullet(mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(-1, -1)));
}

void Ship::updateBullet()
{
	for (EntityVector::size_type i = 0; i < Projectiles.size(); i++)
	{
		Projectiles[i]->update();

		//Removes bullets if not visible
		if (Projectiles[i]->mIsAlive == false)
		{
			Projectiles.erase(std::remove(Projectiles.begin(), Projectiles.end(), Projectiles[i]), Projectiles.end());
		}
	}
	//for (BulletVector::size_type i = 0; i < mBullets.size(); i++)
	//{
	//	mBullets[i].update();

	//	//Removes bullets if not visible
	//	if (mBullets[i].mIsAlive == false)
	//	{
	//		//Projectiles.erase(std::remove(Projectiles.begin(), Projectiles.end(), Projectiles[i]), Projectiles.end());
	//		mBullets.erase(std::remove(mBullets.begin(), mBullets.end(), mBullets[i]), mBullets.end());
	//	}
	//}
}

void Ship::render()
{
	VGCVector index(0, 0);
	VGCAdjustment adjustment(0.5, 0.5);
	VGCDisplay::renderImage(image, index, mPosition, adjustment);

	renderBullet();
	renderText();
}

void Ship::renderBullet()
{
	////Render projectiles
	for (EntityVector::size_type i = 0; i < Projectiles.size(); i++)
	{
		Projectiles[i]->render();
	}
	//Render projectiles
	//for (BulletVector::size_type i = 0; i < mBullets.size(); i++)
	//{
	//	mBullets[i].render();
	//}
}

void Ship::renderText()
{
	//Open font
	static const int fontSize = 30;
	VGCFont font = VGCDisplay::openFont("Arial", fontSize);

	//Render text
	//Score
	const string sText = "Score: " + to_string(mScore);
	VGCDisplay::renderString(font, sText, textColor, scoreTPosition, scoreTAdjustment);

	//Health
	const string hText = "Health: " + to_string(mHealth);
	VGCDisplay::renderString(font, hText, textColor, healthTPosition, healthTAdjustment);

	VGCDisplay::closeFont(font);
}

void Ship::initialize()
{
	//Open on initialization
	image = VGCDisplay::openImage(fileName, 1, 1);
}

void Ship::finalize()
{
	//Close image before application exit
	VGCDisplay::closeImage(image);
}