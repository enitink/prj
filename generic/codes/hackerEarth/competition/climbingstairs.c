#include <stdio.h>

int main()
{
	int a,b,n, r =0;
    scanf("%d%d%d",&a,&b,&n);
    while ( n > 0)
	{
		++r;
		if (!(n - a))
			break;
		n = n - a + b;
	}
	printf("%d\n",r);
	return 0;
}
