#include <stdio.h>

int isPalin(int n)
{
	int rev = 0, rem, tn = n;
	while (tn)
	{
		rem = tn % 10;
		rev = rev * 10 + rem;
		tn /= 10;
	}
	return (n == rev) ? 1 : 0;
}

int main()
{
	int t, a ,b, res, i;
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		scanf("%d%d",&a,&b);
		for (i = a; i <= b; ++i)
			res += (isPalin(i) ? 1 : 0);
		printf("%d\n", res);
	}
	return 0;
}
