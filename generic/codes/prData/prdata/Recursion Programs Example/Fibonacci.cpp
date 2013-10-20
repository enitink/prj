#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int Fibonacci(int n)
{
	if(n == 0 || n == 1)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int Terms;
	
	cout << endl << "Enter No of Terms to Be Generated : ";
	cin >> Terms; 
	
	cout << endl << "The Fibonacci Series is As Below : " << endl;
	
	Terms = Fibonacci(Terms);
	
	cout << "Sum Of The Terms is = " << Terms;
	
	cout << endl;
	return 0;
}
