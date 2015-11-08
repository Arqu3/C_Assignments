#include "Item.h"

using namespace std;

Item::Item(Type type, string name) :
mType(type),
mName(name)
{
}

Item::Type Item::getType()
{
	return mType;
}

void Item::output()
{

}