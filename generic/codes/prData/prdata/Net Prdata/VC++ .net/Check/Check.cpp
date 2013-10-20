#include<iostream>

using namespace std;

int main()
{
	int *ptr;
	int a;
	int row = 8;
	int col = 2;
	
	ptr = new int[16];


	cout << endl << "Enter values for array :";
	for(int i = 0; i < 16; ++i)
		cin >> *(ptr + i);

	cout << endl << "Entered Value of array : ";
	for(int i = 0; i < row; ++i)
	{
		cout << endl;
		for(int j = 0; j < col; ++j)
			cout << "    " << *(ptr + (i * col) + j);
	}
	
	cout << endl;
	return 0;
}