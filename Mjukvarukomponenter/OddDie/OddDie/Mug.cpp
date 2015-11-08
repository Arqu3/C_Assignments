#include "Mug.h"
#include "Die.h"
#include <cassert>

Mug::Mug() :
	mDice()
{

}

Mug::~Mug()
{
	internalClear();
}

void Mug::add(Die *die)
{
	mDice.push_back(die);
}

void Mug::clear()
{
	internalClear();
}

void Mug::shake()
{
	for (DieVector::size_type i = 0; i < mDice.size(); i++)
	{
		mDice[i]->roll();
	}
}

int Mug::read() const
{
	int sum = 0;

	for (DieVector::size_type i = 0; i < mDice.size(); i++)
	{
		sum += mDice[i]->read();
	}
	return sum;
}

void Mug::internalClear()
{
	while (!mDice.empty())
	{
		delete mDice.back();
		mDice.pop_back();
	}
}