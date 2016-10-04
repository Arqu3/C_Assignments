#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*void f(int *p, int *q){
	//Store p in i
	int i = *p;
	//Set p to q
	*p = *q;
	//Set q to i (previously p)
	*q = i;
}
int main(){
	int i = 0;
	int j = 1;
	int k = 2;

	cout << i << " " << j << " " << k << endl;

	f(&i, &j);
	cout << i << " " << j << " " << k << endl;

	f(&j, &k);
	f(&j, &k);
	cout << i << " " << j << " " << k << endl;

	cin.clear();
	cin.get();
	return 0;
}
*/

//Push_back adds element at the end of array
//Pop_back removes element at the end of array

/*typedef vector<int> IntVector;
void f(IntVector ints){
	for (IntVector::size_type i = 0; i < ints.size(); i++){
		cout << ints[i] << " ";
	}
	cout << endl;
}
IntVector g(IntVector ints){
	ints.pop_back();
	return ints;
}
int main(){
	IntVector ints;
	for (int i = 0; i < 10; i++){
		ints.push_back(i);
	}
	f(ints);
	ints = g(ints);
	f(ints);
	ints = g(g(ints));
	f(ints);

	cin.clear();
	cin.get();
	return 0;
}*/

/*int main()
{

	int i = 0;
	cout << i << endl;
	int &j = i;
	j++;
	cout << i << " " << j << endl;
	int &k = j;
	k++;
	cout << i << " " << j << " " << k << endl;

	cin.clear();
	cin.get();
	return 0;
}*/

/*int f(string s){
	int a = 0;
	for (string::size_type i = 0; i < s.length(); i++){
		if (s[i] == 'a'){
			a++;
		}
	}
	return a;
}
bool g(string s){
	for (string::size_type i = 0; i < s.length() / 2; i++){
		if (s[i] != s[s.length() - i - 1]){
			return false;
		}
	}
	return true;
}
int main(){
	string s0 = "aabbccdd";
	string s1 = "xyzzyx";
	cout << f(s0) << " " << f(s1) << endl;
	if (g(s0)){
		cout << s0 << endl;
	}
	if (g(s1)){
		cout << s1 << endl;
	}

	cin.clear();
	cin.get();
	return 0;
}*/

/*int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main()
{
	int temp = 0;
	cin >> temp;

	cout << factorial(temp) << endl;

	std::getchar();

	cin.clear();
	cin.get();

	return 0;
}*/

typedef vector<int> intVector;

int main()
{
	intVector ints;
	int input = 0;

	do
	{
		cin >> input;
		ints.push_back(input);

	} while (input >= 0);

	reverse(ints.begin(), ints.end());

	for (size_t i = 0; i < ints.size(); i++)
	{
		cout << ints[i] << endl;
	}

	cout << endl;

	return 0;
}