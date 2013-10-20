#include <stdio.h>

#define MAX(X, Y) ((X) > (Y)) ? (X) : (Y)

int maxSubArraySum(int* arr, int size)
{
	int i = 0;
	int max_so_far = 0;
	int max_ending_here = 0;
	
	for (	; i < size; ++i )
	{
		max_ending_here = MAX(arr[i], max_ending_here + arr[i]);
		max_so_far = MAX(max_so_far, max_ending_here);
	}
	
	return max_so_far;
}

int main()
{
	int arr[10] = {-2, 4, 2, 3, -12, 5, 9, -3, 4, 1};

	printf("%d\n", maxSubArraySum(arr, 10));
	return 0;
}
