#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<new>

long unsigned lcm(long unsigned a, int b, int i = 2)
{
	int result = 1;
	int temp = 1;
	
	if(a <= 1) 
		return b;
	else
	{
		if(b <= 1)
			return a;
		else
		{
			while ((a % i) == 0 || (b % i) == 0)
			{ 
		      		a = (a % i) == 0 ? a / i : a;
		      		b = (b % i) == 0 ? b / i : b;
				temp *= i;			
			}
			return result * temp * (lcm(a, b, ++i));
		}
	}
}


int main()
{
	int *array;
	int no, i;
	long unsigned result;

	cout << "\n\n\tEnter no of terms in the array : ";
	cin >> no;

	array = new int[no];

	cout << "\n\n\tEnter the elements of the array : ";
	for(i = 0; i < no; ++i)
	{
	   cin >> array[i];
	   result *= array[i] == 0 ? 0 : 1;
	}
        
	if(result == 0)
	   cout << "\n\n\tThe LCM of the entered array is 0 ";
	else
	{
		result = 1;
		for(i = 0; i < no; ++i)
			result = lcm(result , array[i]);
	}
	cout << "\n\n\n\tThe LCM of the entered array is : "  << result;
	

	cout << endl;
	return 0;
}
