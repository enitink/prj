#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<cmath>

#define PI 3.141592

float Sinx(float degreex, float sinx = 0, int i = 1)
{
	if ((sin(degreex) - sinx) <= 0.005 && 
	    (sin(degreex) - sinx) >= -0.005)
		return sinx;
	else
	{
		if ( i != 1 )
			i = (i - 1) * (i) ;
		
		sinx += degreex * PI / i * 180;
		Sinx( degreex, sinx, i += 2 ); 
	}
}

int main()
{
	float x;
	
	cout << "Prg to find the Six(x)";
	cout << "Enter the value of x in degress";
	cin >> x;

	cout << "Sin(" << x << ") = " << Sinx(x);

	return 0;	
}
