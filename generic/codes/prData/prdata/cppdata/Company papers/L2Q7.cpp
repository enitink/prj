#include<iostream>

using std :: cout;
using std :: endl;

int main()
{
	int *a, i;
	
	a = new int[10];
	
	for( i = 0; i < 10; ++i)
		a[i] = i * i;
	
	for( i = 0; i < 10; ++i)
	{
		cout << endl << "value of a = " << a;
		cout << endl << "a[" << i << "] = " << *a++;
		cout << endl << "value of a = " << a + 2;
	}
	
	cout << endl << "value of a = " << a;
	//free(a);
	
	cout << endl;
	return 0;
} 
