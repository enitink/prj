#include <stdio.h>
#include <string.h>

#define SIZE 100001

int main()
{
	char data[SIZE], c;
	int arr[26], tarr[26];
	int n, q, qu, l, r, cnt, cnt1, res, tOdd;
	memset(arr, 0, sizeof(arr));
	scanf("%d%d", &n, &q);
	scanf("%s", data);
	for(cnt = 0; cnt < n; ++cnt)
	{
		arr[data[cnt] - 'a']++;
	}
	for(cnt = 0; cnt < q; ++cnt)
	{
			scanf("%d", &qu);
			if (qu == 1)
			{
					scanf("%d%c%c", &l, &c,&c);
					arr[data[l - 1] - 'a']--;
					arr[c - 'a']++;
					data[l - 1] = c;
			}
			else if(qu == 2)
			{
				scanf("%d%d", &l, &r);
				if ( (n - (r - l)) < (r - l) )
				{
					memcpy(tarr, arr, sizeof(arr));
					for (cnt1 = 0 ; cnt1 < l - 1; ++cnt1)
						tarr[data[cnt1] - 'a']--;
					for (cnt1 = r ; cnt1 < n; ++cnt1)
						tarr[data[cnt1] - 'a']--;
				}
				else
				{
					memset(tarr,0,sizeof(tarr));
					for (cnt1 = l - 1; cnt1 < r; ++cnt1)
					{	
						tarr[data[cnt1] - 'a']++;
					}
				}
				res = 1;
				tOdd = 0;
				for(cnt1 = 0; cnt1 < 26; ++cnt1)
				{
					//printf("%d ", tarr[cnt1]);
					if ( tarr[cnt1] % 2 != 0 )
						tOdd++;
					if ( (tarr[cnt1] % 2 != 0 ) && (tOdd > 1) )
					{
						res = 0;
						break;
					}
				}
				printf("%s\n", res ? "yes" : "no");
				//printf("%s %d %d %s\n", data, l, r, res ? "yes" : "no");
			}
	}
	return 0;
}
