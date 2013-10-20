#include<iostream>

using namespace std;

int main()
{
	int i, j;
	for(i = 0; i < 5; ++i)
	{
		cout << endl;
		for(j = 0; j <= 5 - i; ++j)
			cout << "  ";
		for(j = i; j >= 0; --j)
			cout << " " << j;		
		for(j = j + 2; j <= i; ++j)
			cout << " " << j;
	}
	
	cout << endl;
	return 0;
}
