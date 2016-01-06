#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "Entity.h"
#include <iostream>

class Player : public Entity
{
public:
	Player(sf::Vector2f &position, sf::FloatRect &rectangle);
	~Player();

	void update(EntityVector &entities);
	void draw(sf::RenderWindow &window);

	bool isAlive();
	void setDead();

	sf::Vector2f getPosition();
	sf::FloatRect getRectangle();
	int getScore();

private:
	void move();

	sf::Vector2f mPosition;
	sf::FloatRect mRectangle;
	int mScore;
	int mHealth;
	bool mIsAlive;
	sf::Sprite mSprite;
	sf::Texture mTexture;
};

#endif