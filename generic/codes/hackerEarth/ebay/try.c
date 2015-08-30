#include <stdio.h>
#include <string.h>

int main()
{
    int d, N, K,A, i,j;
    int arr[1000][1000];
    scanf("%d", &d);
	while ( d--)
	{
		scanf("%d%d",&N,&K);
		scanf("%d",&A);
		memset(arr, K, sizeof(arr));
		for(i = 0; i < N; ++i)
		{
				for(j = 0; j < N; ++j)
				{
					printf("%d ", arr[i][j]);
				}
				printf("\n");
		}
	}
    return 0;
}

