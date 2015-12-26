#include "Clock.h"
#include <windows.h>

using namespace std;

int main()
{

	Clock clock;

	clock.setDay(2);
	clock.setHour(23);
	clock.setMinute(59);
	clock.setSecond(55);

	cout << "Day: " << clock.getDay() << endl;
	cout << "Hour: " << clock.getHour() << endl;
	cout << "Minute: " << clock.getMinute() << endl;
	cout << "Second: " << clock.getSecond() << endl;

	cout << endl;

	system("Pause");

	bool done = false;

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