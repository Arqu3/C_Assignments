#include "Game.h"

using namespace std;

//Window
static string name = "Invaders";
static const int width = 600;
static const int height = 640;

//FPS and update time
static const double FPS = 60;
static const double updateT = 1.0 / FPS;

//Ship reference
Ship *ship;

//Menu reference
Menu *menu;

//Enemy
int countE = 5;
float spawnTimer = 0.0f;

Game::Game() :
	mCurrentState(MainMenu),
	isPaused(false),
	endGame(false)
{
	VGCVirtualGameConsole::initialize(name, width, height);
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
			destroy();
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
	ship = new Ship();
	menu = new Menu();
}

void Game::update()
{
	//Update ship
	ship->update();

	//Add enemies
	addEnemies();

	for (EnemyVector::size_type j = 0; j < mEnemies.size(); j++)
	{
		//Update enemies
		mEnemies[j]->update();

		for (EntityVector::size_type i = 0; i < ship->Projectiles.size(); i++)
		{
			if (mEnemies[j]->mRectangle.isInside(ship->Projectiles[i]->mRectangle.getPosition()))
			{
				//Remove bullet and enemy if they collide
				mExplosions.push_back(new Explosion(mEnemies[j]->mPosition, 30));
				ship->Projectiles[i]->mIsAlive = false;
				mEnemies[j]->mIsAlive = false;
			}
		}

		if (ship->mRectangle.isInside(mEnemies[j]->mRectangle.getPosition()))
		{
			//Remove enemy and player health if player and enemy collide
			ship->mHealth -= 10;
			mExplosions.push_back(new Explosion(mEnemies[j]->mPosition, 30));
			mEnemies[j]->mIsAlive = false;
		}

		if (mEnemies[j]->mBulletCD == 0)
		{
			//Add enemy bullets
			mEProjectiles.push_back(new Bullet(mEnemies[j]->mPosition, VGCRectangle(VGCVector(0, 0), 0, 0), VGCVector(0, 1)));
		}

		if (mEnemies[j]->mIsAlive == false)
		{
			//If enemy isn't alive, remove and add score to player
			ship->mScore += 1;
			mEnemies.erase(std::remove(mEnemies.begin(), mEnemies.end(), mEnemies[j]), mEnemies.end());
			break;
		}
		if (!mEnemies[j]->visibilityCheck())
		{
			//If enemy is outside screen, remove it
			mEnemies.erase(std::remove(mEnemies.begin(), mEnemies.end(), mEnemies[j]), mEnemies.end());
			break;
		}
	}

	for (EntityVector::size_type i = 0; i < mEProjectiles.size(); i++)
	{
		mEProjectiles[i]->update();

		if (ship->mRectangle.isInside(mEProjectiles[i]->mRectangle.getPosition()))
		{
			//Remove player health and projectile if they collide
			ship->mHealth -= 10;
			mEProjectiles[i]->mIsAlive = false;
		}

		if (mEProjectiles[i]->mIsAlive == false)
		{
			//If projectile isn't alive, remove it
			mEProjectiles.erase(std::remove(mEProjectiles.begin(), mEProjectiles.end(), mEProjectiles[i]), mEProjectiles.end());
		}
	}

	for (ExplosionVector::size_type i = 0; i < mExplosions.size(); i++)
	{
		mExplosions[i]->update();

		if (mExplosions[i]->mIsAlive == false)
		{
			//Remove explosion image after timer ends
			mExplosions.erase(std::remove(mExplosions.begin(), mExplosions.end(), mExplosions[i]), mExplosions.end());
		}
	}
}

void Game::render()
{
	for (EnemyVector::size_type i = 0; i < mEnemies.size(); i++)
	{
		mEnemies[i]->render();
	}

	for (ExplosionVector::size_type i = 0; i < mExplosions.size(); i++)
	{
		mExplosions[i]->render();
	}

	for (EntityVector::size_type i = 0; i < mEProjectiles.size(); i++)
	{
		mEProjectiles[i]->render();
	}
	ship->render();
}

void Game::addEnemies()
{
	spawnTimer++;
	if (spawnTimer >= 25.0f)
	{
		spawnTimer = 0.0f;
	}

	VGCRandomizer::initializeRandomizer();

	//Randomize starting position and starting direction
	int posX = VGCRandomizer::getInt(0 + 16, VGCDisplay::getWidth() - 16);
	int direction = VGCRandomizer::getInt(0, 1);

	//Add enemies
	if (spawnTimer == 0.0f)
	{
		mEnemies.push_back(new Enemy(VGCVector(posX, -20), VGCRectangle(VGCVector(0, 0), 0, 0), direction, 0.0f));
	}

	VGCRandomizer::finalizeRandomizer();
}

void Game::destroy()
{
	//Remove all objects before closing application
	delete ship;
	delete menu;
	while (!mEnemies.empty())
	{
		delete mEnemies.back();
		mEnemies.pop_back();
	}
	while (!mEProjectiles.empty())
	{
		delete mEProjectiles.back();
		mEProjectiles.pop_back();
	}
	while (!mExplosions.empty())
	{
		delete mExplosions.back();
		mExplosions.pop_back();
	}
}
