#include<iostream>
#include<cstdio>

using std::cin;
using std::cout;
using std::endl;

void InitializeMatrix(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			*(ptr + (i * col) + j) = 0;
}

void DisplayMatrixAddress(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
	{
		cout << endl;
		for(int j = 0; j < col; ++j)
			printf(" %d ", (ptr + (col * i) + j));
	}
}

int main()
{
	int *Array1, *Array2;
	int row = 5, col = 5;
	
	Array1 = new int (row * col);
	Array2 = new int (row * col);
		
	cout << endl << "Address of Array1 : ";
	DisplayMatrixAddress(Array1, row, col);
	
	cout << endl << "Address of Array2 : ";
	DisplayMatrixAddress(Array2, row, col);
	
	cout << endl;
	return 0;
}