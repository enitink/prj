#include<iostream>
#include<iomanip>

using namespace std;
using std :: fixed;

void Fibonacci(int n)
{
	double f = 0;
	double f1 = 1;
	double f2 = 0;
	
	for (int i = 0; i < n; ++ i)
	{
		if(i % 3 == 0)
			cout << endl;
		cout << fixed << setprecision(0) << setw(25) << f;
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		
	}
	
	return ;
}
	
int main()
{
	int n;
	
	cout << "Enter number of terms  : ";
	cin >> n;
	
	Fibonacci(n);
	
	cout << endl;
	return 0;
}
