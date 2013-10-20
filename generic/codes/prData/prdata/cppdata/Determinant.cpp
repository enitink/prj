#include<iostream>
#include<cmath>
#include<iomanip>

using std :: cout;
using std :: cin;
using std :: endl;
using std :: setw;

void DisplayAdd(int **ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
	{
		cout << endl;
		for(int j = 0; j < col; ++j)
			cout << "  " <<  ptr[i][j];
	}
}

void InputMatrix(int **ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			cin >> ptr[i][j];
}

void DisplayMatrix(int **ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
	{
		cout << endl;
		for(int j = 0; j < col; ++j)
		{
			//cout << "  " <<  (ptr + (col * i) + j);
			cout << setw(20) <<  ptr[i][j];
		}
	}
}

void InitializeMatrix(int **ptr, int row, int col)
{
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
			ptr[i][j] = 0;
	}
	cout << endl << "intialize";
}

long int Determinant(int **ptr, int Order)
{
	int **tempptr;
	int i, j, k = 0, l = 0, OrderCounter;
	int CurRow = 0, CurCol = 0;
	long int DeterMinant = 0;
	long int MidVal;

	if(Order == 1)
		return ptr[0][0];
	if (Order == 2)
		return (ptr[0][0] * ((ptr[1][1] * ptr[2][2]) - (ptr[1][2] * ptr[2][1])));
	else
	{
		tempptr = (int **) (calloc(sizeof(int *), Order - 1));
		for(i = 0; i < Order; ++i)
			tempptr[i] = (int *) (calloc(sizeof(int) , Order - 1));		
		
		InitializeMatrix(tempptr, Order - 1, Order - 1);

		for(OrderCounter = 0; OrderCounter <= Order; ++OrderCounter)
		{
			if(ptr[OrderCounter][0] == 0)
				continue;

			CurRow = OrderCounter;
			k = 0;
			for(i = 0; i < Order; ++i)
			{
				if(i == CurRow)
					continue;

				for(j = 1; j < Order; ++j)
				{
					//if(j == CurCol)
					//	continue;
					tempptr[k][l] = ptr[i][j]; 
					++l;
				}
				++k;
				l = 0;
			}
			DisplayMatrix(tempptr, Order - 1, Order - 1);
			MidVal = ptr[OrderCounter][0] * (((int) pow(-1, OrderCounter + 2)) * Determinant(tempptr, Order - 1));
			DeterMinant += MidVal;
		}
	}
	return DeterMinant;
}

int main()
{
	int **a;
	int Order = 4;
	int i,j;

	a = (int **) (calloc(sizeof(int *), 3));
	for(i = 0; i < Order; ++i)
		a[i] = (int *) (calloc(sizeof(int),3));

	for(i = 0; i < Order; ++i)
		for(j = 0; j < Order; ++j)
			a[i][j] = (i+1) * 10 + (j + 1);

	cout << endl << "\t\tProgram to Find the Determinant of a Square Matrix";

	//cout << endl << endl << "Enter Order of the square Matrix : ";
	//cin >> Order;
	
	
	//a = new int(Order * Order);
	//InitializeMatrix(a, Order, Order);
	
	//cout << "\nEnter Data for Matrix :";
	//InputMatrix(a, Order, Order);
	
	cout << "\nEntered Matrix A :";
	DisplayMatrix(a, Order, Order);

	cout << endl << "\nValue of Diterminant is : " << Determinant(a, Order);

	cout << endl;
	return 0;
}
