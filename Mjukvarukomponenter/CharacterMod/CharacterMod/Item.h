#ifndef INCLUDED_ITEM
#define INCLUDED_ITEM

#include "CharacterComponent.h"
#include <string>
#include <iostream>

class Item : public CharacterComponent
{
public:
	Item(Item::Type type, std::string name, int stat);

	virtual Type getType();
	virtual void output();

	virtual int getStat();

private:
	Type mType;
	std::string mName;
	int mStat;
};

#endif