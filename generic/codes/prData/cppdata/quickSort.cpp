#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void DisplayArray(int *array, int no)
{
	cout << " Array : ";
	for (int i = 0; i < no ; ++i)
		cout << " " << array[i];
}
void SwapNos(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;	
}

void QuickSort(int *array, const int SSubs, const int LSubs)
{
	int Position = SSubs;
	int CounterR = 0, CounterL = LSubs + 1;
	
	if (SSubs >= LSubs - 1)
		return;
	else
	{
		int Check = 1;
		while (Check != 0)
		{
			CounterR = CounterL - 1;
			
			do
			{
				Check = 0;
				if (array[Position] > array[CounterR])
				{
					SwapNos(&array[Position], &array[CounterR]);
					CounterL = Position + 1;
					Position = CounterR;
					++Check;
					break;
				}
				--CounterR;
			}while(CounterR >= Position);
			
			do
			{
				Check = 0;
				if (array[Position] < array[CounterL])
				{
					SwapNos(&array[Position], &array[CounterL]);
					SwapNos(&Position, &CounterL);
					++Check;
					break;
				}
				++CounterL;
			}while(CounterL <= Position);
		}
		
		if (Position - 1 >= SSubs)
			QuickSort(array, SSubs, Position - 1);
		
		if (Position + 1 <= LSubs)
			QuickSort(array, Position + 1, LSubs);		
	}
} 

int main()
{
	int *array, no;
	int i;
	
	cout << endl << endl << "\tEnter no of terms in the array : ";
	cin >> no;
	cout << no;

	array = new int[no];

	cout << endl << "\tEnter the elements of the array : ";
	for(i = 0; i < no; ++i)
		cin >> array[i];	
	
	cout << endl << "\tThe Elements of the : ";
	DisplayArray(array, no);
		
	QuickSort(array, 0, no - 1);
	
	cout << endl << endl << "\tThe sorted order : ";
	DisplayArray(array, no);
	
	cout << endl;
	return 0;
}