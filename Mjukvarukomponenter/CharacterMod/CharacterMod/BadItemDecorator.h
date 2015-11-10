#ifndef INCLUDED_BDDECORATOR
#define INCLUDED_BDDECORATOR

#include "CharacterComponent.h"
#include <iostream>

class BadItemDecorator : public CharacterComponent
{
public:
	BadItemDecorator(CharacterComponent *CC);

	virtual Type getType();
	virtual void output();
	virtual int getStat();

private:
	CharacterComponent *mCC;
	void removeQuality();
};

#endif