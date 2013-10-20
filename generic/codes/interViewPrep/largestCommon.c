#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	return;
}

void createMaxHeap(int arr[], int size)
{
	int i, j, k;
	for(i = 1; i < size; ++i)
	{
		j = (i - 1) / 2;
		k = i;
		while( arr[j] < arr[k] )
		{
			swap( arr + j, arr + k );
			k = j;
			j = (j - 1) / 2;
			if( k < 0 || j < 0 )
				break;
		}
	}
	return;
}

void maxHeapify(int arr[], int size)
{
	int root, left, right, max = 0;

	do
	{
		root = max;
		left = 2 * root + 1;
		right = 2 * root + 2;
		if( left >= size)
			break;
		if( right >= size )
			max = left;
		else
			max = arr[left] > arr[right] ? left : right;
		if( arr[max] < arr[root])
			break;
		swap( arr + max, arr + root );
	}while(1);
	return;		
}

int findCommonLargest(int arr1[], int sizeArr1, int arr2[], int sizeArr2)
{
	int i, j;

	createMaxHeap(arr1, sizeArr1);
	createMaxHeap(arr2, sizeArr2);

	for ( i = 0 , j = 0; (i < sizeArr1) &&  (j < sizeArr2); )
	{
		if( arr1[i] == arr2[j] )
			return i;
		if ( arr1[i] > arr2[j] )
		{
			++i;
			maxHeapify(arr1 + i, sizeArr1 - i);
		}
		else
		{
			++j;
			maxHeapify(arr2 + j, sizeArr2 - j);
		}
	}
	return -1;
}

int main()
{
	int arr1[10] = { 5, 9 , 2, 1 , 0, 8, 3, 6, 4, 7};
	int arr2[5] = { 1, 1, 0, 2, 1};
	
	int pt = findCommonLargest(arr1, 10, arr2, 5);
	if(pt == -1)
		printf("No Largest common found");
	else
		printf("Largest common found : %d", arr1[pt]);
	return 0;
}
