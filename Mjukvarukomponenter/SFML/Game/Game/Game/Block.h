#ifndef INCLUDED_BLOCK
#define INCLUDED_BLOCK

#include "Entity.h"
#include <iostream>

class Block : public Entity
{
public:
	Block(sf::Vector2f &position, sf::FloatRect &rectangle);
	~Block();

	void update(float deltaTime);
	void draw(sf::RenderWindow &window);

	bool isAlive();
	void setDead();

	sf::Vector2f getPosition();
	sf::FloatRect getRectangle();
	int getScore();
	int getDamage();
	sf::Sprite getSprite();

private:
	void move(float deltaTime);
	void visibilityCheck();

	sf::Vector2f mPosition;
	sf::FloatRect mRectangle;
	int mScore;
	int mHealth;
	int mDamage;
	bool mIsAlive;
	sf::Sprite mSprite;
	sf::Texture mTexture;
};

#endif