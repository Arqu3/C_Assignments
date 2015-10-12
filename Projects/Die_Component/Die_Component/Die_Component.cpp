// Die_Component.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Die.h"
#include <iostream>
#include <time.h>

using namespace std;

int choice;

int _tmain(int argc, _TCHAR* argv[])
{

	do 
	{
		cout << "Select number of sides: ";

		int NumSideInput = 0;
		cin >> NumSideInput;

		Die *customDie = CreateDie(NumSideInput);

		cout << "Rolling " << "D" << NumSideInput << " :";

		//Initialize randomizer based on time
		srand(time(NULL));

		for (int i = 0; i < 10; i++)
		{
			Roll(customDie);
			cout << Read(customDie) << " ";
		}

		DestroyDie(customDie);

		cout << endl;

		choice = 0;
		cout << "Enter 1 to roll again" << endl;
		cout << "Enter anything else to quit" << endl;
		cin >> choice;
	} while (choice == 1);

	return 0;
}
