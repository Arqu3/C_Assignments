#include <cstdlib>
#include "Character.h"
#include "CharacterComponent.h"
#include "Decorator.h"
#include "Item.h"

using namespace std;

int main()
{
	Item *item = new Item(CharacterComponent::Armor, "Chestplate");

	Character myChar;

	myChar.add(item);
	myChar.output();

	system("Pause");
	
	return 0;
}