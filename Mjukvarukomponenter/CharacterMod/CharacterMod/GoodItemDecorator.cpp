#include "GoodItemDecorator.h"

using namespace std;

GoodItemDecorator::GoodItemDecorator(CharacterComponent *CC) :
	mCC(CC)
{
}

GoodItemDecorator::Type GoodItemDecorator::getType()
{
	return mCC->getType();
}

void GoodItemDecorator::output()
{
	mCC->output();
	addQuality();
}

int GoodItemDecorator::getStat()
{
	return mCC->getStat() * 1.5;
}

void GoodItemDecorator::addQuality()
{
	switch (getType())
	{
	case Type::Armor:
		cout << "It's of extraordinary quality: 1.5 stat multiplier! (you also look damn fine wearing it): +" << getStat() << " protection" << endl;
		break;

	case Type::Consumable:
		cout << "As you give it a taste, you become pretty sure its maker is a master: 1.5 stat multiplier! +" << getStat() << " taste" << endl;
		break;

	case Type::Currency:
		cout << "It's really shiny: 1.5 stat multiplier! +" << getStat() << " value" << endl;
		break;

	case Type::Weapon:
		cout << "It's enchanted: 1.5 stat multiplier! (it also looks freaking sweet!): +" << getStat() << " damage" << endl;
		break;
	}
}