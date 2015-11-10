#include <cstdlib>
#include "Character.h"
#include "CharacterComponent.h"
#include "GoodItemDecorator.h"
#include "BadItemDecorator.h"
#include "Item.h"

using namespace std;

int main()
{
	Item *armor = new Item(CharacterComponent::Armor, "Chestplate", 10);
	Item *consumable = new Item(CharacterComponent::Consumable, "Health potion", 4);
	Item *weapon = new Item(CharacterComponent::Weapon, "Silver Sword", 8);
	Item *currency = new Item(CharacterComponent::Currency, "Gold", 10);

	Character myChar;

	myChar.add(weapon);
	myChar.add(new GoodItemDecorator(armor));
	myChar.add(new BadItemDecorator(consumable));
	myChar.add(new GoodItemDecorator(currency));
	myChar.output();

	system("Pause");

	return 0;
}