#include "Decorator.h"

using namespace std;

Decorator::Decorator(CharacterComponent *CC) :
	mCC(CC)
{
}

Decorator::Decorator()
{}

Decorator::Type Decorator::getType()
{
	return mCC->getType();
}

void Decorator::output()
{
	mCC->output();
}