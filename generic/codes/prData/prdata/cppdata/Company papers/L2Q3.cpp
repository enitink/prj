#include<iostream>
#include<cstring>

using std :: cout;
using std :: endl;

int main()
{
	typedef union
	{
		int a;
		char b[10];
		float c;
	}Union;
	
	Union x, y = { 101 }, z;
	
	for(int i = 0; i < 10; ++i)
		z.b[i] = 100 + i;
	
	x.a = 50;
	strcpy (x.b, "hello");
	x.c = 21.50;
	
	cout << endl << "Union x : " << x.a << " : " << x.b << " : " << x.c;
	cout << endl << "Union y : " << y.a << " : " << y.b << " : " << y.c;	
	cout << endl << "Union z : " << z.a << " : " << z.b << " : " << z.c;
	
	cout << endl;
	return 0;
}