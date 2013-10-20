#include<iostream>

using std :: cout;
using std :: endl;

int main()
{
	struct Data
	{
		int a;
		int b;
	}y[4] = { 1, 10, 3, 30, 2, 20, 4, 40};
	
	struct Data *x = y;
	
	for(int i = 0; i < 4; ++i)
	{
		x->a = x->b , ++x++->b;
		cout << endl << "y[" << i << "].a = " << y[i].a;
		cout << endl << "y[" << i << "].b = " << y[i].b;
	}
	
	cout << endl;
	return 0;
} 
