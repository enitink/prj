#include <stdio.h>
#include <string.h>

#define SIZE 101
#define MODULU 1000007

int main()
{
	int arr[SIZE][SIZE];
	int i, j;

	memset(arr,0,sizeof(arr));

	arr[100][1] = 0;
	arr[1][1] = 1;
	for ( i = 2; i <= 99; ++i)
		arr[100][i] = arr[i][1] = 1;

	for (i = 99; i > 0; --i)
		for (j = 2; j <= 100; ++j)
			arr[i][j] = (arr[i + 1][j] + arr[i][j - 1]) % MODULU;
	printf("{\n");	
	for (i = 98; i <= 100; ++i)
	{
		printf("{");	
		for (j = 1; j <= 3; ++j)
			printf("%d,", arr[i][j]);
		printf("},\n");	
	}
	printf("}\n");	
	return 0;
}
