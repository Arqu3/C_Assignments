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
#include "Menu.h"

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
	typedef std::vector<Bullet*> ProjectileVector;

	ProjectileVector mEProjectiles;

	typedef std::vector<Enemy*> EnemyVector;
	EnemyVector mEnemies;

	float spawnTimer;
	float spawnInterval;

	typedef std::vector<Explosion*> ExplosionVector;
	ExplosionVector mExplosions;

	enum GameState
	{
		InGame,
		Paused,
		MainMenu,
		Over
	};
	GameState mCurrentState;
	bool isPaused;
	bool endGame;
};

#endif