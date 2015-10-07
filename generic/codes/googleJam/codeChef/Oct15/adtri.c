#include <stdio.h>
#include <math.h>

int main()
{
	int t, n, res, i;
	double l, s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res = 0;
		for(i = 2; (i * i) <  4 * (n * n); i += 2)
		{
			l = sqrt(4 * (n * n) - (i * i));
			if (((l - (int)(l) ) * 100)> 0 ) //Just checking if it gives an integer or not
				continue;
			if ( ((int)(l) % 2) == 0 )
			{
				s = sqrt((n * n) - ((l / 2) * (l / 2)));
				if (((s - (int)(s) ) * 100)> 0 ) //Just checking if it gives an integer or not
				{
					if ((2 * n) > (2 * i))
						continue;
					else
						break;
				}
				if ((2 * n) > (2 * s))
				{
					res = 1;
					break;
				}
				else
					break;
			}
		}
		printf("%s\n", (res) ? "YES" : "NO");
	}
	return 0;
}
