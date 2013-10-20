 
#include<iostream>
#include<cstring>

using std :: cout;
using std :: cin;
using std :: endl;

void StringReverse(char *str, int size)
{
	char temp = str[size - 1]; 
	if (no <= 0) 
		return;
	else
	{
		temp = str[size - 1];
		InPlaceStringReverse(str, size - 1);
	}
	str[strlen(str) - size]  = temp;
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
	InPlaceStringReverse(Array, Length);
	cout << Array;
	
	cout << endl;
	return 0;
}
