#include<iostream>
#include<cmath>
#define PI 3.141592

using namespace std;

int main()
{
	float x,s,t;
	int i;
	
	cout << endl << "\t\tProgram to find the exponential value of X";
	cout << endl << "\tEnter Value for X : ";
	cin >> x;

	s = t = i = 1;
	double accuracy = 0.00005 * exp(x);
	while( exp(x) - s > accuracy )
	{
		t = t * x / i;
		s = s + t;
		++i;
	}
	cout << endl << "\tSum of The Series = " << s;
	cout << endl;
	
	return 0;
}
