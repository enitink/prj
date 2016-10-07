#include <iostream>
#include <cstdio>

using std :: cin;
using std :: cout;
using std :: endl;

#define ABC 20
#define XYZ 10
#define XXX ABC - XYZ
#define STR "Hello"

int main()
{
	int a; 

	a = XXX * 10;
	
	cout << endl << "Value of A = " << a;
	
	cout << endl;

	printf(STR);
	return 0;
}
