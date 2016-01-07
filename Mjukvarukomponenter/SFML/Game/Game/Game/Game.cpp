#include "Game.h"

using namespace std;

const int screenW = 800;
const int screenH = 600;

Game::Game() :
mEntities(),
bSpawnInterval(250),
bSpawnTimer(0)
{
	loadPlayer();
	srand(time(NULL));
}

Game::~Game()
{

}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Game");

	window.setMouseCursorVisible(false);

	while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(sf::Color::Black);

		mPlayer->updateMouse(window);
		update();
		draw(window);

		detectCollisions();
		removeDeadEntities();

		window.display();
	}
}

void Game::update()
{
	EntityVector entities(mEntities);
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		entity->update(mEntities);
	}

	addBlocks();
}

void Game::draw(sf::RenderWindow &window)
{
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		entity->draw(window);
	}

	//Draw player score and lives last
	mPlayer->drawScore(window);
	mPlayer->drawHealth(window);
}

void Game::detectCollisions()
{
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		if (mPlayer->getRectangle().intersects(entity->getRectangle()) && mPlayer != entity)
		{
			mPlayer->addScore(entity->getScore());
			entity->setDead();
		}
	}

}

void Game::removeDeadEntities()
{
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
			if (entity != mPlayer)
			{
				delete entity;
			}
		}
	}
	mEntities = entities;
}

void Game::addBlocks()
{
	int posX = rand() % screenW - 32;
	sf::Vector2f spawnPos(posX, -40);

	bSpawnTimer += 0.05f;
	if (bSpawnTimer > bSpawnInterval)
	{
		bSpawnTimer = 0.0f;
	}

	if (bSpawnTimer == 0.0f)
	{
		mEntities.push_back(new Block(spawnPos, sf::FloatRect(0, 0, 0, 0)));
	}
}

void Game::loadPlayer()
{
	while (!mEntities.empty())
	{
		mEntities.pop_back();
	}
	mPlayer = new Player(sf::Vector2f(screenW / 2 - 32, screenH -50), sf::FloatRect(0, 0, 0, 0));
	mEntities.push_back(mPlayer);
}