/******************* PROGRAM FOR CALCULATING VALUE SINX********************
******************** DATE-16/10/03              ***************************
******************** BY:-NITIN KUMAR              *************************/

#include<iostream>
#include<cmath>
#define PI  3.141592

using std :: cout;
using std :: cin;
using std :: endl;


int main()
{
	unsigned long int n = 1;
	double t = 1, s = 0, d, r, temp = 1, x, accuracy;

	cout << "\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SINX";
	cout << "\n\n\t\tENTER THE VALUE OF X IN DEGREES ";
	cin >> x;

	r = x*3.14/180;
	accuracy=sin(x) * PI / 180;

	while ((sin(x) - s) >= accuracy && (sin(x) - s) <= -accuracy)
	{
		t *= (n == 1) ? (r / n) : (r / n * (n - 1));
		
		if(d!=0)
		{
			s += t;
			t = -t;
		}
		n += 2;
	}

	cout << "\n\n\t\tVALUE OF SIN(" << x << ") = " << s;
	cout << "\nValue of cmath sin(x) = " << sin(x);
	cout << "\nvaluue of sin(x) - SIN(X) = " << sin(x) - s;
	cout << "\n\n\n\n\n\n" ;
}
