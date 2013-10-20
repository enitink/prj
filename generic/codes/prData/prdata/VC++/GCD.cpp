#include <iostream.h>

int gcd(int a, int b)
{
	cout << "\na = " << a << "  : b  = " << b;
 	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
		char ans = 'y';
		cout << "\nThis program finds the greatest common divisor "
					"(gcd) of two positive integers. \n";
		do
		{
			int first, second;
			cout << "\nEnter first integer: ";
			cin  >> first;
			cout << "Enter second integer: ";
			cin  >> second;
			cout << "gcd(" << first << ", " << second << ") = "
				 << gcd(first, second) << "\n\n";
			cout << "Do U want To continute (y/n) : ";
			cin  >> ans;
		}while (ans =='y');

		return 0;
}