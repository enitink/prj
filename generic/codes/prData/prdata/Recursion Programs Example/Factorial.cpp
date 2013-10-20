#include<iostream>

using std :: endl;
using std :: cin;
using std :: cout;

int Factorial(int n) 
{
	return (n == 0) ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n;
	
	cout << "\n\n\tEnter Any No. To find out its factorial";
	cin >> n;
	
	cout << "\n\n\tFactorial of Given No. " << n << " is " << Factorial(n);
	cout << endl;
	
	return 0;
}
