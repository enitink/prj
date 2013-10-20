#include<iostream>

using std :: cout;
using std :: endl; 

int main()
{
	cout << endl;
	for(int i = 0; i <= 100; ++i)
		cout << " " << (2 << i);
	
	cout << endl;
	return 0;
}