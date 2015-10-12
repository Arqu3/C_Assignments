#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include <string>
#include <vector>
#include "VGCVirtualGameConsole.h"
#include <algorithm>
#include "Ship.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Explosion.h"

class Game
{
public:
	Game();
	~Game();
	void start();

private:
	void update();
	void render();
	void addEnemies();
	void destroy();
	void handleStates();
	void menuHandler();
	void loadShip();

	typedef std::vector<Entity*> EntityVector;

	EntityVector mEProjectiles;

	typedef std::vector<Enemy*> EnemyVector;
	EnemyVector mEnemies;

	typedef std::vector<Explosion*> ExplosionVector;
	ExplosionVector mExplosions;

	enum GameState
	{
		InGame,
		Paused,
		Menu,
		Over
	};
	GameState mCurrentState;
	bool isPaused;
	bool endGame;
};

#endif