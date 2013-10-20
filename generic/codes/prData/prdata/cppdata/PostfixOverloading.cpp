#include<iostream>

using namespace std;

class Fibonacci
{
private :
	int n;
public :
	Fibonacci()
	{
		n = 0;
	}
	void setint(int n)
	{
		this->n = n;
	}
	void operator++(int)
	{
		int f = 0;
		int f1 = 1;
		int f2 = 0;
		
		for(int i = 0; i < n; ++i)
		{
			cout << " " << f;
			f = f1 + f2;
			f1 = f2;
			f2 = f; 
		}
	}
};

int main()
{
	Fibonacci x;
	int n;
	
	cout << "Enter Any Number : ";
	cin >> n;
	x.setint(n);
	
	cout << endl << "Fibonacci series : ";
	
	x++;
	
	cout << endl;
	return 0;
}   
