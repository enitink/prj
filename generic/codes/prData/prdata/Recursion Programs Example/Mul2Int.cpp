#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

int Multiply(int a, int b)
{
	if(b >= 0)
		return (b <= 1) ? ((b == 0) ? 0 : a) : a + Multiply(a, b - 1);
	else
		return (b == -1) ? -a : -a + Multiply(a, b + 1);
}

int main()
{
	int a, b; 
	
	cout << "Enter Two Nos to find its Product : ";
	cin >> a >> b;
	
	cout << a << " * " << b << " = " << Multiply(a, b);
	cout << endl;
	
	return 0;
}
