#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
	unsigned int a, b;
	
	cout << endl << "Enter First no. : A : ";
	cin >> a;
	cout << endl << "Enter Second no. : B : ";
	cin >> b;
	cout << endl << "Before Changing A = " << a << " And B = " << b;	
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	cout << endl << "After Changing A = " << a <<  "  And B = " << b << endl;
	
	return 0;
}
