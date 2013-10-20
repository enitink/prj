#include<iostream>
#define PI 3.141592

using namespace std;

int main()
{
	float x,s,t;
	int i,k;
	
	cout << endl << "\t\tProgram to find the exponential value of X";
	cout << endl << "\tEnter Value for X : ";
	cin >> x;

	cout << endl << "\tNO.of Terms K : ";
	cin >> k;
	
	s = 1;
	t = 1;
		
	for(i = 1; i <= k; ++i)
	{
		t = t * x / i;
		cout << endl << "T = " << t;
		s = s + t;
	}
	cout << endl << "\tvalue of T = " << t;
	cout << endl << "\tSum of The Series = " << s;
	cout << endl;
	return 0;
}
