#ifndef INCLUDED_DECORATOR
#define INCLUDED_DECORATOR

#include "CharacterComponent.h"

class Decorator : public CharacterComponent
{
public:
	Decorator();
	Decorator(CharacterComponent *CC);

	virtual Type getType();
	virtual void output();

private:
	CharacterComponent *mCC;
};

#endif