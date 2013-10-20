#include <iostream>

using namespace std;

int NumberOfDigits(/* in */ int n)
{
	if (n < 10)
		return (n % 2) == 0 ? 0 : 1;
	else
		return (n % 2) == 0 ? 0 + NumberOfDigits(n / 10) : 1 + NumberOfDigits(n / 10);
}

int main()
{
	char ans = 'y';
	cout << "\nThis program reads in a positive integer "
			"and then computes and prints out \n"
			"the number of odd digits it contains.\n";
	do
	{
		int n;
		cout << "\nEnter the positive integer here: ";
		cin >> n;
		cout << "The number of odd digits in " << n
			 << " is " << NumberOfDigits(n) << ".\n\n";
		cout << "Do U want to Continue";
		cin >> ans;
	}while (ans == 'y');
	
	return 0;
}