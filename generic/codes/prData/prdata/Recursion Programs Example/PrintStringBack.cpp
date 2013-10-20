#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

void PrintStringBack(char *array, int no)
{
	cout << array[no];
	if (no == 0) 
		return;
	else
		PrintStringBack(array, no - 1);	
} 

int main()
{
	char *Array;
	int Length;
	
	cout << "\n\n\tEnter The Length of The String : ";
	cin >> Length;
	
	Array = new char[Length + 1];
	
	cout << "\n\n\tEnter Any String : ";
	cin.ignore(1);
	cin.getline(Array, Length + 1);
	
	cout << "\n\n\tThe String Printed In Reversed Order : ";
	PrintStringBack(Array, Length);
	
	cout << endl;
	return 0;
}
