#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void EnterNumbers(int *Arr)
{
	int i = 0;
	for(   ; i < 10; ++i)
		cin >> Arr[i];
}

void DisplayNumbers(int *Arr)
{
	int i = 0;
	for(   ; i < 10; ++i)
		cout << " " << Arr[i];
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SortNos(int *Arr)
{
	int i = 0, SortRep = 0;
	int ArrSize = 10;
	
	for(   ; i < ArrSize; ++i)
	{
		SortRep = 0;
		
		if(Arr[0] < Arr[i])
		{
			SortRep = 1;
			Swap(Arr + i, Arr);
		}
	}
	if(SortRep == 1)
		SortNos(Arr);
}


int main()
{
	int Arr[10]; //I m keeping fixed size due to lack of time.
	
	cout << "\nEnter 10 Nos. : "; 
	EnterNumbers(Arr);
	
	cout << "\nEntered Nos. Are : ";
	DisplayNumbers(Arr);
	
	cout << "\nEntered Nos. in sorted Order is as follows : ";
	SortNos(Arr);
	DisplayNumbers(Arr);
	
	cout << endl;
} 
