#include<iostream>

using std :: cout;
using std :: endl;

#define calc(a, b) (a * b) / (a - b)


int cal(int a, int b)
{
	return (a * b) / (a - b);
}

int main()
{
	int a = 20, b = 20;

	cout << endl << "result = " <<  calc(a + 4, b - 2);
	cout << endl << "result = " <<  cal(a + 4, b - 2);
	
	cout << endl;
	return 0;
}