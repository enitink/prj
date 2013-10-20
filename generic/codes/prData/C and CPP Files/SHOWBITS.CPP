#include<iostream.h>
#include<conio.h>

void showbits(int n)
{
	int i,k,a;

	clrscr();

	for(i = 15 ; i >= 0; i--)
	{
		a = 1 << i;

		k = n & a;

		k == 0? cout << "0": cout  << "1";
	}
}

int main()
{
	showbits(-10);

	getch();

	return 0;
}

