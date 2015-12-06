#include "Player.h"

using namespace std;

Player::Player(const string &name) :
mName(name)
{
}

void Player::setName(const string &name)
{
	mName = name;
}

const string Player::getName() const
{
	return mName;
}