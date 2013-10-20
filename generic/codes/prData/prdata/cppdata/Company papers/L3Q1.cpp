#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl; 

#include<cstring>

void RevStr(char * ptr, int size, int pos)
{
	if(ptr[pos] == '\0')
		return;
	else
		RevStr(ptr, --size, ++pos);

	cout << ptr[pos];
}

int main()
{
	char *ptr;
	char ans = 'y';
	
	ptr = new char[20];
	
	do
	{
		cout << endl << "Enter any String : ";
		cin >> ptr;
		
		cout << endl << "String : " << ptr;
		
		RevStr(ptr, strlen(ptr), 0);
		
		cout << endl << "Reverse is :" << ptr;
		
		cout << endl << "Do u want to continue(y/n)";
		cin >> ans;
		
	}while(tolower(ans) == 'y');
	
	cout << endl;
	
	return 0;
}