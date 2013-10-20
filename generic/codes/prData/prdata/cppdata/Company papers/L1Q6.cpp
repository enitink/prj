#include<iostream>

using std :: cout;
using std :: endl;

void fn(int a, int b)
{
	cout << endl << "Fn : a = " << a << "\t b = " << b;
} 

int main()
{
	int a = 5;
	
	cout << endl << "Main : " << a++ << "\t" << ++a;
	
	cout << endl << "value of a = " << a;
	
	fn(a, a++);
	
	cout << endl;
	return 0;
}