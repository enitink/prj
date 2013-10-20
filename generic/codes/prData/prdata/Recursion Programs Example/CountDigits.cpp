#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int NumberOfDigits(int n)
{
	if (n < 10)
		return (n % 2) == 0 ? 0 : 1;
	else
		return (n % 2) == 0 ? 0 + NumberOfDigits(n / 10) : 1 + NumberOfDigits(n / 10);
}

int main()
{
	char ans = 'y';
	cout << endl << "This program reads in a positive integer "
			"and then computes and prints out " << endl <<
			"the number of odd digits it contains." << endl;
	do
	{
		int n;
		cout << endl << "Enter the positive integer here: ";
		cin >> n;
		cout << "The number of odd digits in " << n
			 << " is " << NumberOfDigits(n) << endl << endl;
		cout << "Do U want to Continue";
		cin >> ans;
	}while (ans == 'y');
	
	cout << endl;
	return 0;
}