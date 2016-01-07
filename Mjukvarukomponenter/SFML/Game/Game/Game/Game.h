#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "Entity.h"
#include "Player.h"
#include "Block.h"
#include "EntityDecorator.h"

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <time.h>

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	typedef std::vector<Entity*> EntityVector;
	EntityVector mEntities;

	void update();
	void draw(sf::RenderWindow &window);
	void detectCollisions();
	void removeDeadEntities();

	void addBlocks();
	float bSpawnInterval;
	float bSpawnTimer;

	void loadPlayer();
	Player *mPlayer;
};

#endif