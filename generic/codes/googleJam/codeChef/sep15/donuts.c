#include <stdio.h>

int main()
{
	int t, n, m, iC, d, c1, res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		c1 = 0;
		for(iC = 0; iC < m; ++i)
		{
			scanf("%d",&d);
			if ( d == 1 )
				++c1;
		}
	}
	return 0;
}
