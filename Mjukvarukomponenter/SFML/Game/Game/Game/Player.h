#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "Entity.h"
#include <iostream>
#include <string>

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
	int getDamage();

	void addScore(int num);
	void drawScore(sf::RenderWindow &window);
	void drawHealth(sf::RenderWindow &window);

	void updateMouse(sf::RenderWindow &window);

private:
	void updateRectangle();
	void aliveCheck();

	sf::Vector2f mPosition;
	sf::FloatRect mRectangle;

	int mScore;
	int mHealth;
	int mDamage;
	bool mIsAlive;

	sf::Mouse mMouse;

	sf::Sprite mSprite;
	sf::Texture mTexture;

	sf::Font mFont;
	sf::Text mSText;
	sf::Text mHText;
};

#endif