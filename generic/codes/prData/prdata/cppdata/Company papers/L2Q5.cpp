#include<iostream>

using std :: cout;
using std :: endl;

int main()
{
	typedef struct
	{
		int a;
		int b;
		char ch;
		int c;
		int e;
		int d;
	}xyz;
	
	typedef union
	{
		xyz x;
		char y[100];
	}abc;
	
	cout << endl << "Size of XYZ = " << sizeof(xyz) << endl << "Size of abc = " << sizeof(abc);
	cout << endl << "Size of int = " << sizeof(int);
	cout << endl << "Size of int = " << sizeof(char);
	cout << endl << "Size of int = " << sizeof(float);
	
	cout << endl;
	
	return 0;
}
