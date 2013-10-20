#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<new>

int lcm(int a, int b, int i = 2)
{
	int result = 1;
	int temp = 1;
	
	if(a == 1) 
		return b;
	else
	{
		if(b == 1)
			return a;
		else
		{
			while ((a % i) == 0 || (b % i) == 0)
			{ 
		      		a = (a % i) == 0 ? a / i : a;
		      		b = (b % i) == 0 ? b / i : b;
				temp *= i;			
			}
			return temp * (lcm(a, b, ++i));
		}
	}
}


int main()
{
	int result,a,b;
	char ans = 'y';
	do 
	{
		cout << "Enter Two nos. : ";
		cin >> a >> b;	
		if( a == 0 || b == 0)
			result = 0;
		else
			result = lcm(a, b);
		cout << endl << "Result = " << result;
		cout << endl << "Do u want to continue : ";
		cin >> ans;
	}while(ans == 'y'); 
	cout << endl;
	
	return 0;
}
