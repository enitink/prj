#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define SIZE 10001

using namespace std;

typedef struct
{
	vector<int> toMap;
}map_s;

int minRoute(map_s* xy, int n)
{
	int min = SIZE, lmin;
	if (n == 1)
		return 0;
	for (vector<int>::iterator it = xy[n].toMap.begin(); it != xy[n].toMap.end(); ++it)
	{
		lmin = minRoute(xy, (*it));
		min = (min > lmin) ? lmin : min;
	}
	return (1 + min);
}

int main()
{
	int t, n, m, i,x, y;
	map_s* xy = NULL;

	scanf("%d",&t);

	while(t--)
	{
		xy = new map_s[SIZE];
		scanf("%d%d",&n,&m);
		for(i = 0; i < m; ++i)
		{
			scanf("%d%d", &x, &y);
			if ( x > y )
			{
				xy[x].toMap.push_back(y); 
			}
			else
			{
				xy[y].toMap.push_back(x);
			}
		}
		printf("%d\n", minRoute(xy, n));
	}
	return 0;
}
