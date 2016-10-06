#include "stdafx.h"
#include "Die.h"
#include <cstdlib>

using namespace std;

int Roll()
{
	return rand() % 6 + 1;
}

Die::Die()
{
}


Die::~Die()
{
}
