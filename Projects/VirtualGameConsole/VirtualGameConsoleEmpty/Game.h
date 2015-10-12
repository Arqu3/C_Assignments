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

	typedef std::vector<Entity*> EntityVector;
	EntityVector mEntities;

	EntityVector mEProjectiles;

	typedef std::vector<Enemy*> EnemyVector;
	EnemyVector mEnemies;

	typedef std::vector<Explosion*> ExplosionVector;
	ExplosionVector mExplosions;
};

#endif