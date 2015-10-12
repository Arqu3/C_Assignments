#include "OddDie.h"

OddDie::OddDie(Die *die) :
mDie(die)
{
	ensureOddity();
}

OddDie::~OddDie()
{
	delete mDie;
}

void OddDie::roll()
{
	mDie->roll();
	ensureOddity();
}

int OddDie::read() const
{
	return mDie->read();
}

void OddDie::ensureOddity()
{
	while (mDie->read() % 2 == 0)
	{
		mDie->roll();
	}
}