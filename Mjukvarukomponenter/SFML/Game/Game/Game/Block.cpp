#include "Block.h"

using namespace std;

Block::Block(sf::Vector2f &position, sf::FloatRect &rectangle) :
mPosition(position),
mRectangle(rectangle),
mHealth(1),
mScore(1),
mIsAlive(true)
{
	if (!mTexture.loadFromFile("BlockTexture1.png"))
	{
		cout << "Could not load Block1 texture" << endl;
	}
	mSprite.setTexture(mTexture);
}

Block::~Block()
{

}

void Block::update(EntityVector &entities)
{
	move();
}

void Block::draw(sf::RenderWindow &window)
{
	window.draw(mSprite);
	mSprite.setPosition(mPosition);
}

void Block::move()
{
	mPosition.y += 0.1f;

	mRectangle.height = mSprite.getGlobalBounds().height;
	mRectangle.width = mSprite.getGlobalBounds().width;

	mRectangle.left = mPosition.x;
	mRectangle.top = mPosition.y;
}

bool Block::isAlive()
{
	return mIsAlive;
}

void Block::setDead()
{
	mIsAlive = false;
}

sf::Vector2f Block::getPosition()
{
	return mPosition;
}

sf::FloatRect Block::getRectangle()
{
	return mRectangle;
}

int Block::getScore()
{
	return mScore;
}