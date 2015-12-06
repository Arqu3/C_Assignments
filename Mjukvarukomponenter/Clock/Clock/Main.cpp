#include "Clock.h"
#include <windows.h>

using namespace std;

int main()
{

	Clock clock;

	clock.setDay(2);
	clock.setHour(23);
	clock.setSecond(55);
	clock.setMinute(59);

	clock.output();

	bool done = false;
	bool hasInput = false;
	int input = 0;

	while (!done)
	{
		system("cls");

		clock.tick();

		clock.output();

		Sleep(1000);
	}

	system("Pause");

	return 0;
}