#include "Player.h"

using namespace std;

Player::Player(sf::Vector2f &position, sf::FloatRect &rectangle) :
mPosition(position),
mRectangle(rectangle),
mIsAlive(true),
mScore(0),
mHealth(10)
{
	if (!mTexture.loadFromFile("PlayerTexture.png"))
	{
		cout << "Could not load player texture" << endl;
	}
	mSprite.setTexture(mTexture);
}

Player::~Player()
{

}

void Player::update(EntityVector &entities)
{
	move();
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(mSprite);
	mSprite.setPosition(mPosition);
}

void Player::move()
{
	if (mPosition.x > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mPosition.x -= 0.1f;
		}
	}

	if (mPosition.x < 800 - mSprite.getGlobalBounds().width)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mPosition.x += 0.1f;
		}
	}
	mRectangle.height = mSprite.getGlobalBounds().height;
	mRectangle.width = mSprite.getGlobalBounds().width;

	mRectangle.left = mPosition.x;
	mRectangle.top = mPosition.y;
}

bool Player::isAlive()
{
	return mIsAlive;
}

void Player::setDead()
{
	mIsAlive = false;
}

sf::Vector2f Player::getPosition()
{
	return mPosition;
}

sf::FloatRect Player::getRectangle()
{
	return mRectangle;
}

int Player::getScore()
{
	return mScore;
}