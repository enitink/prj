#include <stdio.h>
#include <string.h>

#define flf(x, y)	for (x = 0; x < (y); ++x)
#define SIZE 		10

void populateMatrix();
int findMaxSqMatrixSize(int arr[][], int r, int c)
{
	int maxSize = 0;
	int arr[SIZE];
	int i, j;

	memset(arr, 0, sizeof(arr));

	flf(i, r)
	{
		flf(j, c)
		{
						
		}
	}
	return maxSize;
}

int main()
{
	int arr[SIZE][SIZE];
	printf("%d", findMaxSqMatrixSize());
	return 0;
}
