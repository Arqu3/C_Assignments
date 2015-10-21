#include "Game.h"

using namespace std;

//FPS and update time
static const double FPS = 60;
static const double updateT = 1.0 / FPS;

Game::Game() :
	mEntities(),
	mCurrentState(MainMenu),
	isPaused(false),
	endGame(false),
	spawnTimer(0.0f),
	spawnInterval(50.0f)
{
	Ship::initialize();
	Bullet::initialize();
	Enemy::initialize();
	Explosion::initialize();
	menu = new Menu();
}


Game::~Game()
{
	Ship::finalize();
	Bullet::finalize();
	Enemy::finalize();
	Explosion::finalize();
	VGCVirtualGameConsole::finalize();
}

void Game::start()
{
	//Open timer
	VGCTimer timer = VGCClock::openTimer(updateT);

	while (endGame == false && VGCVirtualGameConsole::beginLoop())
	{
		//Update objects
		VGCClock::reset(timer);
		if (VGCDisplay::beginFrame())
		{
			//Clear background
			VGCColor backgroundColor(255, 0, 0, 0);
			VGCDisplay::clear(backgroundColor);

			handleStates();
			menuHandler();

			//Render objects while not in the main menu
			if (mCurrentState != MainMenu)
			{
				render();
			}
			menu->update();

			switch (mCurrentState)
			{
			case MainMenu:
				//Insert Menu rendering
				menu->renderMainMenu();
				break;

			case InGame:
				//Update entities
				update();
				removeDeadEntities();
				break;

			case Paused:
				//Insert Pause rendering
				menu->renderPause();
				break;

			case Over:
				//Insert Game over rendering
				menu->renderGameOver();
				break;
			}

			VGCDisplay::endFrame();
		}
		VGCVirtualGameConsole::endLoop();
		VGCClock::wait(timer);
	}

	VGCClock::closeTimer(timer);
	destroy();
}

void Game::handleStates()
{
	//Update only if player is alive
	if (mCurrentState == InGame)
	{
		if (!ship->isAlive())
		{
			mCurrentState = Over;
		}
	}

	if (mCurrentState == Over)
	{
		//Exit to menu when pressing escape
		if (VGCKeyboard::wasPressed(VGCKey::Q_KEY))
		{
			mCurrentState = MainMenu;
		}
		//Reload game when pressing R
		if (VGCKeyboard::wasPressed(VGCKey::R_KEY))
		{
			destroy();
			loadShip();
			mCurrentState = InGame;
		}
	}

	//Toggle game pause
	if (mCurrentState == Paused || mCurrentState == InGame)
	{
		//Can only toggle if InGame or Paused
		if (VGCKeyboard::wasPressed(VGCKey::ESCAPE_KEY))
		{
			isPaused = !isPaused;
		}
		//Switch states
		if (isPaused == true)
		{
			mCurrentState = Paused;
		}
		else
		{
			mCurrentState = InGame;
		}
	}
	//Exit to main menu if paused & pressed Q
	if (mCurrentState == Paused)
	{
		if (VGCKeyboard::wasPressed(VGCKey::Q_KEY))
		{
			//Remove all objects on exit
			destroy();
			//Create new menu
			menu = new Menu();
			mCurrentState = MainMenu;
			isPaused = false;
		}
	}
}

void Game::menuHandler()
{
	if (mCurrentState == MainMenu)
	{
		//Start game when pressing Enter
		if (VGCKeyboard::wasPressed(VGCKey::RETURN_KEY))
		{
			//Load new ship on startup
			loadShip();
			mCurrentState = InGame;
		}
		//Close program when pressing Escape
		if (VGCKeyboard::wasPressed(VGCKey::ESCAPE_KEY))
		{
			endGame = true;
		}
	}

}

void Game::loadShip()
{
	ship = new Ship(VGCVector(VGCDisplay::getWidth() / 2, VGCDisplay::getHeight() / 2));
	mEntities.push_back(ship);
}

void Game::update()
{
	EntityVector entities(mEntities);
	for (EntityVector::iterator i = entities.begin(); i != entities.end(); i++)
	{
		Entity *entity = *i;
		entity->update(mEntities);
	}

	addEnemies();

	////Update ship
	//ship->update();

	////Add enemies
	//addEnemies();

	//for (EnemyVector::size_type j = 0; j < mEnemies.size(); j++)
	//{
	//	//Update enemies
	//	mEnemies[j]->update();

	//	for (EntityVector::size_type i = 0; i < ship->Projectiles.size(); i++)
	//	{
	//		if (mEnemies[j]->mRectangle.isInside(ship->Projectiles[i]->mRectangle.getPosition()))
	//		{
	//			//Remove bullet and enemy if they collide
	//			mExplosions.push_back(new Explosion(mEnemies[j]->getPosition(), 30));
	//			ship->Projectiles[i]->mIsAlive = false;
	//			mEnemies[j]->setDead();
	//		}
	//	}

	//	if (ship->mRectangle.isInside(mEnemies[j]->mRectangle.getPosition()))
	//	{
	//		//Remove enemy and player health if player and enemy collide
	//		ship->takeDMG(10);
	//		mExplosions.push_back(new Explosion(mEnemies[j]->getPosition(), 30));
	//		mEnemies[j]->setDead();
	//	}

	//	if (mEnemies[j]->canAddBullet())
	//	{
	//		//Add enemy bullets
	//		mEProjectiles.push_back(new Bullet(mEnemies[j]->getPosition(), VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(0, 1)));
	//	}

	//	if (!mEnemies[j]->isAlive())
	//	{
	//		//If enemy isn't alive, remove and add score to player
	//		ship->addScore();
	//		mEnemies.erase(std::remove(mEnemies.begin(), mEnemies.end(), mEnemies[j]), mEnemies.end());
	//		break;
	//	}
	//	if (!mEnemies[j]->visibilityCheck())
	//	{
	//		//If enemy is outside screen, remove it
	//		mEnemies.erase(std::remove(mEnemies.begin(), mEnemies.end(), mEnemies[j]), mEnemies.end());
	//		break;
	//	}
	//}

	//for (ProjectileVector::size_type i = 0; i < mEProjectiles.size(); i++)
	//{
	//	mEProjectiles[i]->update();

	//	if (ship->mRectangle.isInside(mEProjectiles[i]->mRectangle.getPosition()))
	//	{
	//		//Remove player health and projectile if they collide
	//		ship->takeDMG(5);
	//		mEProjectiles[i]->mIsAlive = false;
	//	}

	//	if (mEProjectiles[i]->mIsAlive == false)
	//	{
	//		//If projectile isn't alive, remove it
	//		mEProjectiles.erase(std::remove(mEProjectiles.begin(), mEProjectiles.end(), mEProjectiles[i]), mEProjectiles.end());
	//	}
	//}

	//for (ExplosionVector::size_type i = 0; i < mExplosions.size(); i++)
	//{
	//	mExplosions[i]->update();

	//	if (mExplosions[i]->mIsAlive == false)
	//	{
	//		//Remove explosion image after timer ends
	//		mExplosions.erase(std::remove(mExplosions.begin(), mExplosions.end(), mExplosions[i]), mExplosions.end());
	//	}
	//}
}

void Game::render()
{
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		entity->render();
	}
}

void Game::addEnemies()
{
	spawnTimer++;
	if (spawnTimer >= spawnInterval)
	{
		spawnTimer = 0.0f;
	}

	VGCRandomizer::initializeRandomizer();

	//Randomize starting position and starting direction
	int posX = VGCRandomizer::getInt(0 + 16, VGCDisplay::getWidth() - 16);
	int direction = VGCRandomizer::getInt(0, 1);
	VGCVector pos(posX, -20);
	VGCRectangle rect(pos, 0, 0);
	float bulletCD(0.0f);

	//Add enemies
	if (spawnTimer == 0.0f)
	{
		mEntities.push_back(new Enemy(pos, rect, direction, bulletCD));
	}

	VGCRandomizer::finalizeRandomizer();
}

void Game::removeDeadEntities()
{
	//Remove each entity that returns isAlive() = false
	EntityVector entities;
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		if (entity->isAlive())
		{
			entities.push_back(entity);
		}
		else
		{
			delete entity;
		}
	}
	mEntities = entities;
}

bool Game::isOverlap(Entity *entity0, Entity *entity1)
{
	//Collision using pythagoras theorem
	const VGCVector position0 = entity0->getPosition();
	const int X0 = position0.getX();
	const int Y0 = position0.getY();
	const int R0 = entity0->getRadius();

	const VGCVector position1 = entity1->getPosition();
	const int X1 = position1.getX();
	const int Y1 = position1.getY();
	const int R1 = entity1->getRadius();

	const int DX = X0 - X1;
	const int DY = Y0 - Y1;

	return (DX * DX) + (DY * DY) < (R0 + R1) * (R0 + R1);
}

void Game::destroy()
{
	//Remove all objects before closing application
	//delete ship;
	delete menu;
	while (!mEntities.empty())
	{
		delete mEntities.back();
		mEntities.pop_back();
	}
}
