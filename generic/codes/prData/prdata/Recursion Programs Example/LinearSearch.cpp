 
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

bool LinearSearch(const int *array, const int key, const int Size)
{
	if (Size <= 1) 
		return false;
	else 
		return (array[Size - 1] == key) ? true : LinearSearch(array, key, Size - 1);
}
int main()
{
	int *array, no;
	int i;
	int key;
	char ans = 'y';
	
	cout << endl << endl << "\tEnter no of terms in the array : ";
	cin >> no;
	
	array = new int[no];

	cout << endl << "\tEnter the elements of the array : ";
	for(i = 0; i < no; ++i)
		cin >> array[i];
		
	cout << endl << "\tThe Elements of the : ";
	DisplayArray(array, no);
	
	do
	{
		cout << endl << "\tEnter the No to find in the array : ";
		cin >> key;
			
		cout << endl << "The No : " << key;
		
		if (LinearSearch(array, key, no - 1))
			cout << " : Found";
		else
			cout << " : Not Found";
	
		cout << endl << "Do U want to continue (y/n) ";
		cin >> ans;
	}while(ans == 'y');
	
	cout << endl;
	return 0;
}