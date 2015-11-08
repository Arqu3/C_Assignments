#include <iostream>
#include "Die.h"
#include "StandardDie.h"
#include "OddDie.h"
#include "Mug.h"

using namespace std;

int main()
{

	Mug mug;
	mug.add(new StandardDie(StandardDie::die6()));
	mug.add(new OddDie(new StandardDie(StandardDie::die12())));
	cout << "Shaking: ";

	for (int i = 0; i < 10; i++)
	{
		cout << mug.read() << " ";
		mug.shake();
	}

	cout << endl;

	system("Pause");

	return 0;
}