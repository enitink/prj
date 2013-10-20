#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<cstring>

bool Palindrome(char *array, int no)
{
	if (no <= (strlen(array) / 2) + 1) 
		return (array[strlen(array) - no] == array[no - 1]) ? true : false;
	else
		return (array[strlen(array) - no] == array[no - 1]) && (Palindrome(array, no - 1) ? true : false);
}

int main()
{
	char *Array;
	int Length;
	char ans;

	do
	{
		cout << "\n\tEnter The Length of The String : ";
		cin >> Length;
			
		Array = new char[Length + 1];
		
		cout << "\n\tEnter Any String : ";
		cin.ignore(1);
		cin.getline(Array, Length + 1);
		
		cout << "\n\tThe Original String is : " << Array << " : is : ";
		if (Palindrome(Array, Length))
			cout << " Palindrome";
		else
			cout << " Not Palindrome";

		cout << endl << "\tDo u want to continue : ";
		cin >> ans;
	}while (ans == 'y');
	
	cout << endl;
	return 0;
}
