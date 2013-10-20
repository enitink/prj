#include<stdio.h>

void EnterNumbers(int *Arr)
{
	int i = 0;
	for(   ; i < 10; ++i)
		scanf(" %d", Arr[i]);
}

void DisplayNumbers(int *Arr)
{
	int i = 0;
	for(   ; i < 10; ++i)
		printf("%d ", Arr[i]);
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
}


int main()
{
	int Arr[10]; //I m keeping fixed size due to lack of time.
	
	printf("\nEnter 10 Nos. : ");
	EnterNumbers(Arr);
	
	printf("\nEntered Nos. Are : ");
	DisplayNumbers(Arr);
	
	printf("\nEntered Nos. in sorted Order is as follows : ");
	SortNos(Arr);
	DisplayNumbers(Arr);
	
	printf("\n");
} 
