#include<iostream>

using namespace std;

int ReverseNo(int number)
{
	int reverseno = 0;
	while(number != 0 ) 
	{
		reverseno = reverseno * 10 + (number % 10);
		number /= 10;
	}
	
	return reverseno;
}

bool PalindromeNo( int number, int revnumber)
{
	return ( number == revnumber ? true : false);
}

int main()
{
	int number;
	int temp;
	
	do
	{
		cout << endl << "Enter Any Number to find out if it is Palindrome or Not : ";
		cin >> number;
		
		temp = ReverseNo( number );
		if (PalindromeNo( number, temp ))
			cout << endl << "Number : " << number << " : is Palindrome.";
		else
			cout << endl << "Number : " << number << " : is Not Palindrome.";
	}while(number != 0);
	
	cout << endl;
	return 0;
}