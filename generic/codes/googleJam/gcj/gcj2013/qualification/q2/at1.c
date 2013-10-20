#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
	int T, N, M, c, d, r, caseNo = 1;
	int arr[SIZE];
	scanf("%d", &T);
	printf("%d\n", T);

	while (T--)
	{
		scanf("%d%d", &N, &M);
		printf("%d %d\n", N, M);
		r = 1;
		bzero(arr, sizeof(arr));

		N--;
		for (c = 0; c < M; ++c)
		{
			scanf("%d", &d);
			printf("%d ", d);
			arr[c] = d;
		}
		if ( N )
			printf("\n");
		while (N--)
		{
			for (c = 0; c < M; ++c)
			{
				scanf("%d", &d);
				printf("%d ", d);
				if (!r)
					continue;
				if (c == 0) { if (d > arr[c + 1] ) { r = 0; continue; } }
				else if ( (d < arr[c - 1] ) && (d < arr[c]) ) { r = 0; continue; }
				arr[c] = d;
			}
			if ( N )
				printf("\n");
			if (!r)
				continue;
		}

		if (r == 0) printf("Case #%d: NO\n", caseNo++);
		else printf("Case #%d: YES\n", caseNo++);
	}
	return 0;
}
