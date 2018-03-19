/* 
pointers.cpp
Feb 8, 2017
Sapphire

*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int main(int argc, char ** argv) {
	int num;
	cout << "Enter an even number: " << endl;
	cin >> num;
	while(num != 0)
	{
	if(num % 2 != 0)
	{
		cout << "Not an even number \nTry again: " << endl;
		cin >> num;
	}
	cout << "Enter another even integer: \n(type 0 to quit)" << endl;
	cin >> num;
}
	cout << endl;

	for(int i = 0; i < 22; i++)
	{
		setw(22);
		cout << "*";
	}
	cout << "\nThank you, come again!" << endl;

	for(int i = 0; i < 22; i++)
	{
		setw(22);
		cout << "*";
	}
	cout << endl;
// Diamond Pattern
	int s = 10;
	for(int i = 1; i < 5; i++)
	{
		cout << setw(s);
		s--;
		for(int j = 0; j < (2*i-1); j++)
		{
			cout << "0";
		}
		cout << endl;
	}
	for(int i = 5; i > 0; i--)
	{
		cout << setw(s);
		s++;
		for(int j = 0; j < (2*i-1); j++)
		{
			cout << "0";
		}
		cout << endl;
	}
return 0;
}

/*
 *
 *
 *
 *
 *
 *
 *
 */
