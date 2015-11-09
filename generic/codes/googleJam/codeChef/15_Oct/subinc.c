#include <cstdio>

#define SIZE 100000

int main()
{
	int t,n,i,res;
	int arr[SIZE];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		res = n;
		for(i = 0; i < n;++ i)
		{
			scanf("%d", &arr[i]);
		}
	}
	return 0;
}
