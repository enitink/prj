 
 
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void PrintAnArr(int *array, int no)
{
	cout << " : " << array[no - 1];
	if (no == 1) 
		return;
	else
		PrintAnArr(array, no - 1);
	
} 

int main()
{
	int *array, no;
	
	cout << "\n\n\tEnter no of terms in the array : ";
	cin >> no;

	array = new int[no];

	cout << "\n\n\tEnter the elements of the array : ";
	for(int i = 0; i < no; ++i)
		cin >> array[i];	
	
	cout << "\n\n\tThe Elements of the Arrary are : ";
	PrintAnArr(array, no);
	
	cout << endl;
	return 0;
}
