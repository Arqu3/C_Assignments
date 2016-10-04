#include "Die.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Die::~Die()
{

}

int Die::randomValue(int value)
{
	return rand() % value + 1;
}

Die::Die(Type type) :
mValue(0),
mMax(0)
{
	switch (type)
	{
	case D4:
		mMax = 4;
		break;

	case D6:
		mMax = 6;
		break;

	default:
		cerr << "Unknown Die type";
		exit(EXIT_FAILURE);
	}
	mValue = randomValue(mMax);
}

void Die::roll()
{
	mValue = randomValue(mMax);
}

int Die::read() const
{
	return mValue;
}