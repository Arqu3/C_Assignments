#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> intVector;

int main()
{
	int input = 0;
	intVector ints;

	cout << "Enter a positive number sequence. End it with a negative number:" << endl;

	do
	{
		cin >> input;
		ints.push_back(input);

	} while (input >= 0);

	reverse(ints.begin(), ints.end());

	cout << "Here is that same sequence in reverse order" << endl;

	for (size_t i = 0; i < ints.size(); i++)
	{
		cout << " " << ints[i];
	}

	cout << endl;

	return 0;
}