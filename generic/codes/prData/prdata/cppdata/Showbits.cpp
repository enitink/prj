#include<iostream>

using std :: cout;
using std :: endl;
using std :: cin;

void showbits(int n)
{
	int i,k,a;

	for(i = 15; i >= 0 && n != 0; --i)
	{
		a = 1 << i;
		k = n & a;
		k == 0? cout << "0": cout  << "1";
		//n = n >> 1;
	}

	cout << endl;
}

int main()
{
	int n;

	cout <<  endl << "Enter Any No. To find its  Binary Equivalent : ";
	cin >> n;
	showbits(n);
	
	return 0;
}

