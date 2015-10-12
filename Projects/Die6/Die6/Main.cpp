#include <iostream>
#include "Die.h"
#include "OddDie.h"
#include "FileDie.h"
#include "Mug.h"
#include <time.h>

using namespace std;

int main()
{
	Mug mug;
	mug.add(new FileDie("Die.txt"));
	mug.add(new OddDie(new FileDie("Die.txt")));

	cout << "Shaking: " << endl;

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		mug.shake();
		cout << mug.read() << " ";
	}
	cout << endl;

	return 0;
}