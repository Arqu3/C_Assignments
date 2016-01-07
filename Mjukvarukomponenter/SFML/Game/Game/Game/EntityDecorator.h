#ifndef INCLUDED_ENTITYDECORATOR
#define INCLUDED_ENTITYDECORATOR

#include "Entity.h"

class EntityDecorator : public Entity
{
public:
	enum Type
	{
		Fast,
		Damage,
		Score,
		Horizontal
	};

	EntityDecorator(Type type, Entity *entity);
	~EntityDecorator();

	void update(EntityVector &entities);
	void draw(sf::RenderWindow &window);
	bool isAlive();
	void setDead();

	sf::Vector2f getPosition();
	sf::FloatRect getRectangle();
	int getScore();
	int getDamage();
	sf::Sprite getSprite();

private:
	Entity *mEntity;
	Type mType;
};

#endif