#include <stdio.h>
#include <math.h>

#define SIZE 500
#define DISTANCE(X,Y) ( abs(arr[X].r - arr[Y].r) + abs(arr[X].c - arr[Y].c) )

typedef struct
{
	int r;
	int c;
}loc_s;

int main()
{
	loc_s arr[SIZE*SIZE];
	int t,n, cR, cC,d;
	scanf("%d",&t);
	unsigned long long int lRes;
	while (t--)
	{
		scanf("%d",&n);
		for( cR = 0; cR < n; ++cR)
			for (cC = 0; cC < n; ++cC)
			{
				scanf("%d", &d);
				arr[d - 1].r = cR;
				arr[d - 1].c = cC;
			}
		lRes = 0;
		for ( cR = 1; cR < (n * n); ++cR)
		{
			lRes += DISTANCE(cR - 1, cR); 
		}
		printf("%llu\n", lRes);
	}
}
