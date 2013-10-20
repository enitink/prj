#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void InitializeMatrix(int *ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			*(ptr + (i * col) + j) = 0;
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
			cout << "  " <<  *(ptr + (col * i) + j);
	}
}

void multiplication(int *a, int *b, int *c, int row, int col1, int col)
{
    int i,j,k;

    for(i = 0; i < row; ++i)
    {
       for(j = 0 ; j < col; ++j)
       {
	   *(c + (col * i) + j) = 0;
	   for(k = 0; k < col1; ++k)
	   {
	     *(c + (col * i) + j) = *(c + (col * i) + j) + *(a + (col1 * i) + k) * *(b + (col * k) + j);
	   }
       }
    }
}

int main()
{
	int *a, *b, *c;
	int Row1, Row2, Col1, Col2;
	
	cout << endl << "\t\tProgram to Find the Multiplication of Two matrices";

	cout << endl << endl << "Enter Row & Column of First Matrix : ";
	cin >> Row1;
	cin >> Col1;

	cout << "Enter Row & Column of Second Matrix : ";
	cin >> Row2;
	cin >> Col2;  

	a = new int(Row1 * Col1);
	InitializeMatrix(a, Row1, Col1);

	b = new int(Row2 * Col2);
	InitializeMatrix(b, Row2, Col2);
	
	if(Col1 != Row2)
	{
		cout << endl << endl << "Matrix Multiplication not Possible as Col of first Matrix is not equal to Row of Second";
		exit(0);
	}
	
	c = new int(Row1 * Col2);
	InitializeMatrix(c, Row1, Col2);
	
	cout << "Enter Data for Matrix 1 :";
	InputMatrix(a, Row1, Col1);
	
	cout << "Enter Data for Matrix 2 :";
	InputMatrix(b, Row2, Col2);

	cout << "Entered Matrix A :";
	DisplayMatrix(a, Row1, Col1);

	cout << endl << "Entered Matrix B :";
	DisplayMatrix(b, Row2, Col2);

	multiplication(a, b, c, Row1, Col1, Col2);
	
	cout << endl << "Result Matrix :";
	DisplayMatrix(c, Row1, Col2);
	
	cout << endl;
	return 0;
}