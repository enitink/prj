#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
using std :: setf;

int main()
{
	int x;
	
	setf(ios :: fixed);
	do
	{
		cout << endl << "X = ";
		cin >> x;
		
		cout << endl << "0.0001% accuracy for Sin(" << x 
		     << " ) = " << sin(x) * 0.000001;
	}while(x != 1000);
	
	cout << endl;
	return 0;
}
