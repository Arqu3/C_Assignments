#include "Item.h"

using namespace std;

Item::Item(Type type, string name, int stat) :
mType(type),
mName(name),
mStat(stat)
{
}

Item::Type Item::getType()
{
	return mType;
}

void Item::output()
{

	cout << mName << ": ";

	switch (mType)
	{
	case Type::Armor:
		cout << "A piece of protective armor: +" << mStat << " protection" << endl;
			break;

	case Type::Consumable:
		cout << "Something you can eat or drink: +" << mStat << " taste" << endl;
		break;

	case Type::Currency:
		cout << "It has value to some people: +" << mStat << " value" << endl;
		break;

	case Type::Weapon:
		cout << "Mostly used to hurt things: +" << mStat << " damage" << endl;
		break;
	}
}

int Item::getStat()
{
	return mStat;
}