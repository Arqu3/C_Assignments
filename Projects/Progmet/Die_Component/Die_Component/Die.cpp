#include "stdafx.h"
#include "Die.h"
#include <cstdlib>

using namespace std;

struct Die 
{
	int value;
	int max;
};

static int RandomValue(int max)
{
	return rand() % max + 1;
}

Die* CreateDie(int max)
{
	Die *die = new Die;
	die->max = max;
	die->value = RandomValue(max);
	return die;
}

void DestroyDie(Die *die)
{
	delete die;
}

void Roll(Die *die)
{
	die->value = RandomValue(die->max);
}

int Read(const Die *die)
{
	return die->value;
}