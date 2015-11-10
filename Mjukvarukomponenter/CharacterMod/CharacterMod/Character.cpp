#include "Character.h"

using namespace std;

Character::Character() :
mComponents()
{
}

Character::~Character()
{
	internalClear();
}

void Character::add(CharacterComponent *CC)
{
	mComponents.push_back(CC);
}

void Character::output()
{
	for (CCVector::size_type i = 0; i < mComponents.size(); i++)
	{
		mComponents[i]->output();
		cout << endl;
	}
}

void Character::internalClear()
{
	while (!mComponents.empty())
	{
		delete mComponents.back();
		mComponents.pop_back();
	}
}