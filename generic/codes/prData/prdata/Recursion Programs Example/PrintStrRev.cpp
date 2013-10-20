#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void Print(char * array, int pos)
{
	if (array[pos] != '\0') 
		Print(array, pos + 1);
	
	cout << " " << array[pos];
} 

int main()
{
	char * array;
	int no;
	
	cout << "\n\n\tEnter no of terms in the array : ";
	cin >> no;

	array = new char[no];

	cout << "\n\n\tEnter the elements of the array : ";
	for(int i = 0; i < no; ++i)
		cin >> array[i];
	
	cout << "\n\n\tThe Elements of the Arrary in reversed order are : ";
	Print(array, 0);
	
	cout << endl;
	return 0;
}
