 
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

int SumEleOfArr(int *array, int no)
{
	return (no == 1) ?  array[no - 1] :  array[no - 1] + SumEleOfArr(array, no - 1);
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
	
	cout << "\n\n\tSum of The Elements of the Arrary = " << SumEleOfArr(array, no);
	
	cout << endl;
	return 0;
}
