#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void SelectionSort(int *array, int no)
{
	static int a = no;
	int temp = array[a - no];
	int i;
	int sub = a - no;
	
	if (no == 1)
		return;
	else
	{	
		for(i = a - 1; i > a - no; --i)
			if(temp >= array[i])
			{
				sub = i;
				temp = array[i];
			}
		array[sub] = array[a - no];
		array[a - no] = temp;
		SelectionSort(array, no - 1);
	}
} 

int main()
{
	int *array, no;
	int i;
	
	cout << endl << endl << "\tEnter no of terms in the array : ";
	cin >> no;

	array = new int[no];

	cout << endl << "\tEnter the elements of the array : ";
	for(i = 0; i < no; ++i)
		cin >> array[i];	
	
	cout << endl << "\tThe Elements of the Arrary : " << endl;
	for(i = 0; i < no; ++i)
		cout << "  " << array[i];
		
	SelectionSort(array, no);
	
	cout << endl << endl << "\tThe Elements of the Arrary in The sorted order : " << endl;
	for(i = 0; i < no; ++i)
		cout << "  " << array[i];
	
	cout << endl;
	return 0;
}