#include <stdio.h>
#include <string.h>

int main()
{
	int twtArr[1000];
	int n, k, d, count = 0;
	char click[20];

	memset(twtArr, 0, sizeof(twtArr));

	scanf("%d %d", &n, &k);

	while(k--)
	{
		scanf("%s %d", click, &d);
		switch(click[2])
		{
		case 'I':
			if(twtArr[d - 1])
			{
				twtArr[d - 1] = 0;
				--count;
			}
			else
			{
				twtArr[d - 1] = 1;
				++count;
			}
		break;

		case 'O':
			memset(twtArr, 0, sizeof(twtArr));
			count = 0;
		break;
		}
		printf("%d\n", count);
	}
}
