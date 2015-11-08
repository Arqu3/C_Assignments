#ifndef INCLUDED_CHARACTER
#define INCLUDED_CHARACTER

#include "CharacterComponent.h"
#include <vector>
#include <iostream>

class Character
{
public:
	Character();
	~Character();
	void add(CharacterComponent *CC);
	void output();

private:
	typedef std::vector<CharacterComponent*> CCVector;
	CCVector mComponents;
};

#endif