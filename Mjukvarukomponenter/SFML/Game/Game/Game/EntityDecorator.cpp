#include "EntityDecorator.h"

using namespace std;

EntityDecorator::EntityDecorator(Type type, Entity *entity):
mEntity(entity),
mType(type)
{
	switch (mType)
	{
	case Type::Damage:
		getSprite().setColor(sf::Color::Blue);
		break;
	}
}

EntityDecorator::~EntityDecorator()
{

}

void EntityDecorator::update(EntityVector &entities)
{
	return mEntity->update(entities);
}

void EntityDecorator::draw(sf::RenderWindow &window)
{

	return mEntity->draw(window);
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
		return mEntity->getScore() + 3;
		break;
	}
}

int EntityDecorator::getDamage()
{
	return mEntity->getDamage() + 1;
}

sf::Sprite EntityDecorator::getSprite()
{
	return mEntity->getSprite();
}