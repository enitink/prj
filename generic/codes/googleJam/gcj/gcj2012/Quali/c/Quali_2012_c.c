#include <sdtio.h>

int main()
{
	int t, i, a, b, j, res, tj, k;
	int al[14];

	scanf("%d", &t);
	for (i = 1; i <= t; ++i)
	{
		res = 0;
		scanf("%d %d", &a, &b);
		for(j = a; j <= b; ++j)
		{
			k = 13;
			tj = j;
			while(tj)
			{
				al[k--] = a % 10;
				a /= 10;
			}
			
		}
	}

	return 0;
}
