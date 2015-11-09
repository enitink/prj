#include <stdio.h>
#include <string.h>

#define SIZE 100

enum bool{false, true};

int main()
{
	int r, c;
	int data;
	int i, j;
	int arr[SIZE];
	int validLoc = -1;
	bool valid = false;

	scanf("%d %d", &r, &c);

	memset(arr, 0, sizeof(arr));

	for (i = 0; i < r, ++i)
	{
		valid = false;
		for (j = 0; j < c; ++j)
		{
			scanf("%d", data);
			validLoc = (validLoc == -1) ? j : (arr[validLoc] > data) ? j : validLoc;
			if (data >= arr[j])
			{
				arr[j] = data;
				if (validLoc == j)
					valid = true;
			}
		}
	}
	return 0;
}
