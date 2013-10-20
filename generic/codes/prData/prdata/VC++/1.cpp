#include<iostream>
using namespace std;

int main()
{
	int n, temp, rem, checkn, pos = 1, rev = 0;
	
	cout << endl << "Enter Any Number";
	cin >> n;
	cout << endl << "Enter The Number to find";
	cin >> checkn;

	temp = n;

	while( temp != 0)
	{
		rem = temp % 10;
		rev = rev * 10 + rem;
		temp /= 10;
	}

	temp = rev; 
	
	do
	{
		rem = temp % 10;
		
		if(rem == checkn)
		{
			cout << endl << "Number : " << checkn << " : Found in : " << n  << " : At Pos : " << pos;
		}
		
		++pos;
		temp /= 10;
	}while( temp != 0 );

	cout << endl;
	return 0;
}
