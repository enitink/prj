#include<iostream>

using namespace std;

int main()
{
	for(int i = 100; i <= 200; ++i)
	{
		cout << endl << i;
		cout << "\t" << ios :: oct << i;
		cout << "\t" << ios :: hex << i;
	}
	
	return 0;
}
