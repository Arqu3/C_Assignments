// Hello Die.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Die.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Alternative dice roll
	cout << "Enter number of rolls" << endl;
	int NumberOfRolls = 0;

	cin >> NumberOfRolls;
	//Can and will store letters in int?
	cout << NumberOfRolls << endl;

	for (int i = 0; i + 1 < NumberOfRolls; i++)
	{
		int Value = rand() % 6 + 1;
		cout << "Roll " << i << ": " << Value << endl;
	}

	return 0;
}

