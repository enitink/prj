#include<iostream>

using std :: cout;
using std :: endl;

#define ABC 1
#define XYZ 1
#define XXX ABC - XYZ

int main()
{
	int a; 

	a = XXX * 10;
	
	cout << endl << "Value of A = " << a;
	
	cout << endl;
	return 0;
}