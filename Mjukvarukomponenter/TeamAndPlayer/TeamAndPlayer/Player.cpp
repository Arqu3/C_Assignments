#include "Player.h"

using namespace std;

Player::Player(const string &name) :
mName(name)
{
}

void Player::setName(string &name)
{
	mName = name;
}

string Player::getName() 
{
	return mName;
}