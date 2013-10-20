#include<iostream>
#include<cstring>
#define SIZE 10
#define BUFFERSIZE 50

using namespace std;

void SortString(char StringPtr[][BUFFERSIZE])
{
	int i, j;
	char temp[BUFFERSIZE];
	
	for( i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE - i - 1 ; j++)
		{
			if(strncmp(StringPtr[j], StringPtr[j + 1], BUFFERSIZE) > 0)
			{
				strcpy( temp, StringPtr[j] );
				strcpy( StringPtr[j], StringPtr[j + 1]);
				strcpy( StringPtr[j + 1], temp);
			}
		}
	}
	return;
}  

int main()
{
	char Strings[SIZE][BUFFERSIZE];
	int i;
	
	cout << endl << "Enter SIZE Strings Below :" << endl;
	for(i = 0; i < SIZE; ++i)
	{
		cin.getline(Strings[i],50);
	}
	
	cout << "The Strings are : ";
	for(i = 0; i < SIZE; ++i)
		cout << endl << Strings[i];
	
	SortString(Strings);
	
	cout << endl << "The Sorted Strings are : ";
	for(i = 0; i < SIZE; ++i)
		cout << endl << Strings[i];
	
	cout << endl;
	return 0;
}
