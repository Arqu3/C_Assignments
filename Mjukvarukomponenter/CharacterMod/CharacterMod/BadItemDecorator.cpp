#include "BadItemDecorator.h"

using namespace std;

BadItemDecorator::BadItemDecorator(CharacterComponent *CC) :
	mCC(CC)
{
}

BadItemDecorator::Type BadItemDecorator::getType()
{
	return mCC->getType();
}

void BadItemDecorator::output()
{
	mCC->output();
	removeQuality();
}

int BadItemDecorator::getStat()
{
	return mCC->getStat() - 5;
}

void BadItemDecorator::removeQuality()
{
	switch (getType())
	{
	case Type::Armor:
		cout << "Oh no, It's broken! -5 to stats! +" << getStat() << " protection" << endl;
		break;

	case Type::Consumable:
		cout << "Just by smelling it you're pretty sure it's rotten.. -5 to stats: " << getStat() << " taste" << endl;
		break;

	case Type::Currency:
		cout << "Damn, they're cursed.. -5 to stats: +" << getStat() << " value" << endl;
		break;

	case Type::Weapon:
		cout << "This is way heavier than it should be, -5 to stats: +" << getStat() << " damage" << endl;
		break;
	}
}