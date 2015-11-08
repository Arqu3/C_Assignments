#ifndef INCLUDED_ITEM
#define INCLUDED_ITEM

#include "Decorator.h"
#include <string>

class Item : public Decorator
{
public:
	Item(Item::Type type, std::string name);

	Type getType();
	void output();

private:

	Type mType;
	std::string mName;
};

#endif