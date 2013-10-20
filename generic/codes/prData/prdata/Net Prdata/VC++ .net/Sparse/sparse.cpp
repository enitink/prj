#include<iostream>
#define NULL 0

using std::cin;
using std::cout;
using std::endl;

void InitializeMatrix(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			*(ptr + (i * col) + j) = NULL;
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
			cout << "   a[" << i << "][" << j << "] = " << *ptr++;		
	}
}

int CheckSparseMatrix(int *ptr, int row, int col)
{
	int Check = 0;
	
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			if(*(ptr + (col * i )+ j) != 0)
				++Check;
		}

		return (Check < (0.2 * (row * col)))? Check : -1;	
}

int * CreateNewMatrix(int *ptr, int row, int col, int elements)
{
	int *NewMatrix = new int[elements * 3];
	int TempIndex = 0;

	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
		{
			if(*(ptr + (col * i )+ j) != 0)
			{
				*(NewMatrix + (3 * TempIndex)) = i;
				*(NewMatrix + (3 * TempIndex) + 1) = j;
				*(NewMatrix + (3 * TempIndex) + 2) = *(ptr + (col * i )+ j);
			}
		}
	return NewMatrix;
}

int main()
{
	int *Array1, *Array2;
	int *NewArray1, *NewArray2;
	int row, col;
	int elements;
	
	cout << endl << "Enter Row Value ";
	cin >> row;
	cout << endl << "Enter Col Value ";
	cin >> col;
	
	Array1 = new int (row * col);
	Array2 = new int (row * col);

	InitializeMatrix(Array1, row, col);
	InitializeMatrix(Array2, row, col);
	
	cout << endl << "Enter Values for Array1 : ";
	InputMatrix(Array1, row, col);
	
	cout << endl << "Enter Values for Array2 : ";
	InputMatrix(Array2, row, col);
	
	cout << endl << "Values of Array1 : ";
	DisplayMatrix(Array1, row, col);
	
	cout << endl << "Values of Array2 : ";
	DisplayMatrix(Array2, row, col);

	/*elements = CheckSparseMatrix(Array1, row, col);
	cout << endl << "Elements = " << elements;
    
	if (elements != -1)
	{
		NewArray1 = CreateNewMatrix(Array1, row, col, elements);
		cout << endl << "The new matrix created is as below (New Array1): ";
		DisplayMatrix(NewArray1,elements,3);
	}
	else 
		cout << endl << "Array1 is not sparse Matrix";

	elements = CheckSparseMatrix(Array2, row, col);
	cout << endl << "Elements = " << elements;

	if (elements != -1)
	{
		NewArray2 = CreateNewMatrix(Array2, row, col, elements);
		cout << endl << "The new matrix created is as below (New Array2): ";
		DisplayMatrix(NewArray1,elements,3);
	}
	else
		cout << endl << "Array1 is not sparse Matrix";*/

	cin >> elements;
	return 0;
}