#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void IntializeMatrix(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			*(ptr + (i * col) + j) =0;
}

void InputMatrix(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			cin >> *(ptr + (i * col) + j);
}

void DisplayMatrix(int *ptr, int row, int col)
{ 
	for(int i = 0; i < row; ++i)
	{
		cout << endl;
		for(int j = 0; j < col; ++j)
			cout << " " << *(ptr + (i * col) + j);
	}
}

void InplaceTranspose(int *ptr, int row, int col)
{
	int temp;
	
	if(row == col)
	{
		for(int i = 0; i < row; ++i)
		{	for(int j = 0; j < col && j != i; ++j)
			{
				temp = *(ptr + (i * col) + j);
				*(ptr + (i * col) + j) = *(ptr + (j * col) + i) ;
				*(ptr + (j * col) + i) = temp;
			}
		}
	}
	else
	{
		cout << endl<< "Matrix Can't be transposed";
	}
}

int main()
{
	int row, col;
	
	cout << endl << "Enter Rows : ";
	cin >> row;
	cout << endl << "Enter Cols : ";
	cin >> col;
	
	int *Array = new int(row * col);
	
	IntializeMatrix(Array, row, col);
	
	cout << endl << "Enter the Matrix : ";
	InputMatrix(Array, row, col);
	
	cout << endl << "Entered Matrix : ";
	DisplayMatrix(Array, row, col);
	
	InplaceTranspose(Array, row, col);
	
	cout << endl << "Entered Matrix after Tranposing: ";
	DisplayMatrix(Array, row, col);
	
	cout << endl;
	
	return 0;
}