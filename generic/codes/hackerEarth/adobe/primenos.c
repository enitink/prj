#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	int i;
	for (i=2; i <= sqrt(n); ++i)
	{
		if ( (n % i) == 0 )
			return 0;
	}
	return 1;
}

int main()
{
	int i = 2,count = 0;
	for (;;++i)
	{
		if ( isPrime(i) ){ ++count;
			printf("%d,",i*i);	}
		if ((i * i) > 1000000000)
			break;
	}
	return 0;
}
