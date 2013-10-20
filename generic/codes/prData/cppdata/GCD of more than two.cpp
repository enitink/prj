#include <iostream.h>

int Gcd(int a, int b)
{
	cout << "\na = " << a << "  : b  = " << b;
 	if (b == 0)
		return a;
	else
		return Gcd(b, a%b);
}

int gcdofall(int *ptr,int noofterms)
{
	static int gcd = 5;
	if ( noofterms <= 0)
		return gcd;
	else
	{
		gcd = Gcd(gcd, ptr[noofterms]);	
		cout << "gcd = " << gcd;
		gcdofall(ptr, --noofterms);
	}
	cout << "1 : 1 :gcd = " << gcd;
	return 1;
}

int main()
{
		int *Ptr, noofterms;
		cout << "\nThis program finds the greatest common divisor "
					"(gcd) of positive integers. \n";
		cout << "\nEnter the Nos. of terms";
		cin >> noofterms;
		
		Ptr = new int[noofterms];

		for (int i = 0; i < noofterms; ++i)
		{
			cout << "Enter integer: [" << i << "] : ";
			cin  >> Ptr[i];
		}		

		cout << "GCD of The Given Terms : ";

		for(i = 0; i < noofterms; ++i)
			cout << "\n Integer: [" << i << " ] = " << Ptr[i];

		cout << "\n Is : " << gcdofall(Ptr, noofterms-1);
		return 0;
}