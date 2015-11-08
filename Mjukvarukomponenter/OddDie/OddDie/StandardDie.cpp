#include "StandardDie.h"
#include <cstdlib>

using namespace std;

static int randomValue(int numSide)
{
	return rand() % numSide + 1;
}

StandardDie::StandardDie(int max) :
	mValue(randomValue(max)),
	mMax(max)
{
}

void StandardDie::roll()
{
	mValue = randomValue(mMax);
}

int StandardDie::read() const
{
	return mValue;
}

StandardDie StandardDie::die4()
{
	return StandardDie(4);
}

StandardDie StandardDie::die6()
{
	return StandardDie(6);
}

StandardDie StandardDie::die8()
{
	return StandardDie(8);
}

StandardDie StandardDie::die10()
{
	return StandardDie(10);
}

StandardDie StandardDie::die12()
{
	return StandardDie(12);
}

StandardDie StandardDie::die20()
{
	return StandardDie(20);
}