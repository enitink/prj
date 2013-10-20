#include <iostream>

using std :: cin;
using std :: cout;
using std :: endl;
    
int Gcd(int a, int b)
{
	return (b == 0) ? a : Gcd(b, a%b);
}

int GcdOfAll(int *ptr,int noofterms)
{
	static int gcd = ptr[0];
	if ( noofterms <= 0)
		return gcd;
	else
	{
		gcd = Gcd(gcd, ptr[noofterms]);	
		GcdOfAll(ptr, --noofterms);
	}
	return gcd;
}

int main()
{
		int *Ptr, noofterms, i;
		cout << "\nThis program finds the greatest common divisor "
					"(gcd) of positive integers. \n";
		cout << "\nEnter the Nos. of terms";
		cin >> noofterms;
		
		Ptr = new int[noofterms];

		for (i = 0; i < noofterms; ++i)
		{
			cout << "Enter integer: [" << i << "] : ";
			cin  >> Ptr[i];
		}		

		cout << "GCD of The Given Terms : ";

		for(i = 0; i < noofterms; ++i)
			cout << "\n Integer: [" << i << "] = " << Ptr[i];

		cout << "\n Is : " << GcdOfAll(Ptr, noofterms-1);
		cout << endl;
		return 0;
}
