#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<new>

int MinValue(int *array, int n)
{
	int temp;
	if (n == 2)
		return (array[n- 1] < array[n - 2]) ? array[n - 1] : array[n - 2];
	else
	{
		temp = MinValue(array, n - 1);
		return (array[n - 1] < temp) ? array[n- 1] : temp;
	}
} 

int main()
{
	int *array;
	int no, i;
	long unsigned result;

	cout << "\n\n\tEnter no of terms in the array : ";
	cin >> no;

	array = new int[no];

	cout << "\n\n\tEnter the elements of the array : ";
	for(i = 0; i < no; ++i)
	   cin >> array[i];
	        
	cout << "\n\n\n\tThe Minimum Value of the entered array is : "  << MinValue(array, no);
	

	cout << endl;
	return 0;
}
