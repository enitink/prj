#include <stdio.h>

typedef unsigned long long int ULLInt;
 
ULLInt fact(int n)
{
	return (n == 1) ? 1 : n * fact(n - 1);
}

ULLInt facto(int n)
{
	int i = 1;
	ULLInt f = 1;
	for ( ; i < n; ++i )
	{
		f *= i;
		printf("%d %llu\n", i,f);
	}
}
int main()
{
	int t, n;
	scanf("%d", &t);
 
	while(t--)
	{
		scanf("%d", &n);
		printf("%llu\n", facto(n));
	}
	return 0;
}
