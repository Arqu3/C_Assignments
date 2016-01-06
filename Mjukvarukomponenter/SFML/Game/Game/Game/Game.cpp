#include "Game.h"

using namespace std;

const int screenW = 800;
const int screenH = 600;

Game::Game() :
mEntities()
{
	loadPlayer();
}

Game::~Game()
{

}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Game");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

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
}

void Game::draw(sf::RenderWindow &window)
{
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		entity->draw(window);
	}
}

void Game::detectCollisions()
{
	for (EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		Entity *entity = *i;
		if (mPlayer->getRectangle().intersects(entity->getRectangle()) && mPlayer != entity)
		{
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

void Game::loadPlayer()
{
	while (!mEntities.empty())
	{
		mEntities.pop_back();
	}
	mPlayer = new Player(sf::Vector2f(screenW / 2 - 32, screenH -50), sf::FloatRect(0, 0, 0, 0));
	mEntities.push_back(mPlayer);

	Block *block1 = new Block(sf::Vector2f(screenW / 2 - 16, 50), sf::FloatRect(0, 0, 0, 0));
	mEntities.push_back(block1);
}