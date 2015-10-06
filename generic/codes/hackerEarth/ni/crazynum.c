#include <stdio.h>

#define MODULO 1000000007

int res;

int rec(int num, int n, int size, int nc)
{
	//printf("%d %d %d %d\n", num, n, size, nc);
	int tnum;
	if ((nc < 0) || (nc > 9))
		return -1;
	if (n == size)
		return num;
	else
	{
		num *= 10;
		++size;
		if ( (tnum = rec(num + nc + 1, n, size, nc + 1) != -1) && (size == n))
		{
			//printf("%d\n",num + nc + 1);
			res = (res + 1) % MODULO;
		}
		if ( (tnum = rec(num + nc - 1, n, size, nc - 1) != -1) && (size == n))
		{
			//printf("%d\n",num + nc - 1);
			res = (res + 1) % MODULO;
		}
		return res;
	}
}

int main()
{
    int t,n,i,j,num,cn;
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d", &n);
		if( n == 1 )
		{
			printf("10\n");
			continue;
		}
		res = 0;
		for(i = 1; i <= 9; ++i)
		{
			rec(i, n, 1, i);
		}
		printf("%d\n",res);
    }
    return 0;
}

