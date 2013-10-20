#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

float Power(float a, int p)
{
	if (a == 0)
		return 0;
	else
		if(p >= 0)
			return (p == 0) ? 1 : ((p == 1) ? a : a * Power(a, p - 1));
		else
			return (p == -1) ? 1/a : 1/a * Power(a, p + 1);
}

int main()
{
	int a, p;
	
	cout << "Enter any no and its power (respectevly): ";
	cin >> a >> p;

	cout << a << " To the Power of " << p << " = " << Power(a, p);
	cout << endl;

	return 0;
}
