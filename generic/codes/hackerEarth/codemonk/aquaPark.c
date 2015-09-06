#include <stdio.h>

typedef struct
{
	int x1;
	int y1;
	int x2;
	int y2;
}lineSeg;

int main()
{
	int X, N, counter = 0, i;
	lineSeg arr[101];
	lineSeg data;

	scanf("%d%d",&X,&N);
	memset(arr, 0, sizeof(arr));
	while (N--)
	{
		scanf("%d%d%d%d", &data.x1, &data.y1, &data.x2, &data.y2);
		for (i=0; i <= counter; ++i)
		{
			if(arr[i].x1 <= data.x1)
				break;
		}
	}

	return 0;
}
