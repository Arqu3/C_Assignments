#include "EntityDecorator.h"

using namespace std;

EntityDecorator::EntityDecorator(Type type, Entity *entity):
mEntity(entity),
mType(type)
{
	mSprite = mEntity->getSprite();
	switch (mType)
	{
	case Type::Fast:
		mSprite.setColor(sf::Color::Blue);
		break;

	case Type::Damage:
		mSprite.setColor(sf::Color::Red);
		break;

	case Type::Score:
		mSprite.setColor(sf::Color::Yellow);
		break;

	case Type::Horizontal:
		mSprite.setColor(sf::Color::Green);
		break;
	}
}

EntityDecorator::~EntityDecorator()
{

}

void EntityDecorator::update(float deltaTime)
{
	return mEntity->update(deltaTime);
}

void EntityDecorator::draw(sf::RenderWindow &window)
{
	window.draw(mSprite);
	mSprite.setPosition(mEntity->getPosition());
}

bool EntityDecorator::isAlive()
{
	return mEntity->isAlive();
}

void EntityDecorator::setDead()
{
	return mEntity->setDead();
}

sf::Vector2f EntityDecorator::getPosition()
{
	return mEntity->getPosition();
}

sf::FloatRect EntityDecorator::getRectangle()
{
	return mEntity->getRectangle();
}

int EntityDecorator::getScore()
{
	switch (mType)
	{
	case Type::Damage:
		return mEntity->getScore() + 1;
		break;

	case Type::Fast:
		return mEntity->getScore() + 1;
		break;

	case Type::Score:
		return mEntity->getScore() + 4;
		break;
	}
}

int EntityDecorator::getDamage()
{
	switch (mType)
	{
	case Type::Damage:
		return mEntity->getDamage() + 1;
		break;
	}
}

sf::Sprite EntityDecorator::getSprite()
{
	return mSprite;
}