/******************* PROGRAM FOR CALCULATING VALUE SINX********************
******************** DATE-16/10/03              ***************************
******************** BY:-NITIN KUMAR              *************************
STILL NOT SOLVED*/

#include<iostream>
#include<cmath>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>

T absfn(T x)
{
	if (x >=0 )
		return x;
	else
		return -x;
}

int main()
{
	long int n = 2;
	double t = 1, s = 0, r, temp = 1, x, accuracy, count = 0;

	cout << "\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SINX";
	cout << "\n\n\t\tENTER THE VALUE OF X IN DEGREES ";
	cin >> x;

	r = x*3.14/180;
	accuracy = sin(x) * 1 / 100;

	cout << endl << "Accuracy = " << accuracy;
	cout << endl << "absfn() = " << absfn(sin(x) - s);

	s = r;
	while (absfn(sin(x) - s) >= accuracy)
		
	{
		t *= (r * r / (n * (n - 1)));
		
		t = -t;
		s += t;
		n += 2;
		
		++count;
	}
	
	cout << "Sin(" << x << ") = " << s;
	return 0;
}
