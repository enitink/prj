#include <stdio.h>
#include <stdlib.h>

#define SIZE 500000000
int arr[SIZE];

int possiblities(int n)
{
	if ((arr[n] != 0) || (n == 2))
		return arr[n];
	else
	{
		arr[n] = ( 6 * possiblities(n - 1)) % (1000000007);
		return arr[n];
	}
}

int main()
{
	arr[2] = 0;
	arr[3] = 6;

    int t, n, res;
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d", &n);
    	printf("%d\n", possiblities(n));
    }
    return 0;
}
