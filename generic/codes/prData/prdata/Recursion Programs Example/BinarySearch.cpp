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

bool BinarySearch(const int *array, const int key, 
                  const int StartSubscript, const int LastSubscript)
{
	if (StartSubscript >= LastSubscript) 
		return ( array[LastSubscript] == key ) ? true : false;
	else if ( array[ (LastSubscript + StartSubscript)/ 2 ] == key)
		return true;
	else if ( array[ (LastSubscript + StartSubscript)/ 2 ] > key)
		return (BinarySearch( array, key, StartSubscript,
		                   (( LastSubscript + StartSubscript ) / 2 ))) ? 
			true : false;  
	else if ( array[ (LastSubscript + StartSubscript)/ 2 ] < key)
		return (BinarySearch( array, key, 
		                   (( LastSubscript + StartSubscript ) / 2 ) + 1,
				      LastSubscript) ) ? 
			true : false;  
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
	
	SelectionSort(array, no);
	
	cout << endl << endl << "\tThe sorted order : ";
	DisplayArray(array, no);	
	
	do
	{
		cout << endl << "\tEnter the No to find in the array : ";
		cin >> key;
			
		cout << endl << "The No : " << key;
		
		if (BinarySearch(array, key, 0, no - 1))
			cout << " : Found";
		else
			cout << " : Not Found";
	
		cout << endl << "Do U want to continue (y/n) ";
		cin >> ans;
	}while(ans == 'y');
	
	cout << endl;
	return 0;
}