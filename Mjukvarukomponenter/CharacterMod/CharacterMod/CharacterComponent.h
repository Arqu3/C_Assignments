#ifndef INCLUDED_CC
#define INCLUDED_CC

class CharacterComponent
{
public:
	CharacterComponent();
	enum Type
	{
		Weapon,
		Armor,
		Consumable,
		Currency
	};

	virtual Type getType() = 0;
	virtual void output() = 0;
};

#endif