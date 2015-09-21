#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 100001

using namespace std;

int main()
{
	int t, n, m, iC, d, res, arr[SIZE], toLink;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(iC = 0; iC < m; ++iC)
		{
			scanf("%d",&arr[iC]);
		}

		sort(arr,arr + m);
		toLink = m - 1;
		iC = 0;
		res = 0;
		while (toLink > 0)
		{
			if (toLink > arr[iC])
			{
				toLink -= (arr[iC] + 1);
				res += arr[iC];
			}
			else if (toLink == arr[iC])
			{
				toLink = 0;
				res += arr[iC];
			}
			else
			{
				res += toLink;
				toLink = 0;
			}
			++iC;
		}
		printf("%d\n", res);
	}
	return 0;
}
