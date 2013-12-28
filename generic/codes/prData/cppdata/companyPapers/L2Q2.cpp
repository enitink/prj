#include<iostream>

using std :: cout;
using std :: endl;

static int val = 5;

void fn()
{
	static int val = 0;
	for(; val < 5; val++) 
		cout << endl << " " << val;
} 

int main()
{
	
	while(val--) fn();

	cout << endl << "in main " << val;
	
	cout << endl;
	return 0;
}
