#include <stdio.h>

int main()
{
	int t, n, s, p, i, j, d, k, l, m, res, poss, spcl;

	scanf("%d", &t);
	for(i = 1; i <= t; ++i)
	{
		scanf("%d %d %d", &n, &s, &p);
		res = 0;
		for(j = 0; j < n; ++j)
		{
			scanf("%d", &d);
			printf("d : %d\n", d);
			poss = 0;
			spcl = -1;
			for(k = 10; k >= p; --k)
			{
				for(l = 0; l <= 2; ++l)
				{
					m = d - (2 * k - l);
					if ( m > 10 || m < 0)
						break;
					if ( k - m > 2 )
						continue;
					if ( (abs(k - m) == 2 ) || (abs( k - l - m) == 2)  || (l == 2))
						spcl = 1;
					else
						spcl = 0;
					poss = 1;
					printf("%d %d %d %d\n", k, k - l, m, spcl);
					if (spcl == 0)
						break;
				}
				if (spcl == 0)
					break;
			}
			printf("poss:%d spcl:%d s:%d\n", poss, spcl, s);
			if ( (s <= 0) && (spcl == 1) )
				continue;
			if (spcl == 1)			
				--s;
			if ( poss == 1)
				++res;
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
