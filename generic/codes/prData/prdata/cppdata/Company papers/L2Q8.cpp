//Write a program to calculate number of 1's (bit) in a given integer number i.e. Number of 1's in the given integer's equivalent binary
//representation

#include<iostream>
#include<cstring>

using std :: cin;
using std :: cout;
using std :: endl;

int main()
{
	int IntNo, TIntNo;
	char ans = 'y';
	int NoofOne;
	
	do
	{
		NoofOne = 0;
		
		cout << endl << "Enter any integer to count no of 1's bit in it : ";
		cin >> IntNo;
		
		TIntNo = IntNo;
		
		while(TIntNo)
		{
			if((TIntNo & 1) == 1)
				++NoofOne;
			TIntNo = TIntNo >> 1;
		}
		
		cout << endl << "No of 1's bit in " << IntNo << " is " << NoofOne;
		
		cout << endl << "Do u want to continue(y/n)";
		cin >> ans;
		
	}while(tolower(ans) == 'y');
	
	cout << endl;
	
	return 0;
}