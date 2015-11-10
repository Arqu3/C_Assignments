#ifndef INCLUDED_GDDECORATOR
#define INCLUDED_GDDECORATOR

#include "CharacterComponent.h"
#include <iostream>

class GoodItemDecorator : public CharacterComponent
{
public:
	GoodItemDecorator(CharacterComponent *CC);

	virtual Type getType();
	virtual void output();
	virtual int getStat();

private:
	CharacterComponent *mCC;

	void addQuality();
};

#endif