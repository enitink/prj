#include <stdio.h>
#include <string.h>

#define fabi(a,b)	for(int i = a; i < b; ++i)
#define fabj(a,b)	for(int j = a; j < b; ++j)

bool checkSum(int c[], int size, int sum)
{
	bool* arr = new bool[sum+1];
	bzero(arr, sizeof(bool) * sum+1);
	bool result = false;
	arr[0] = true;
	//printf("  i,  j, arr[j - c[i]] ,  c[i] , arr[c[i]]");
	fabi(0,size)
	{
		for ( int j = sum; j >= c[i]; --j)
		{
			//printf("\n%3d %3d %12d %8d %10d", i,j,arr[j - c[i]], c[i], arr[c[i]]);
			if ( arr[j - c[i]] )
                arr[j] = true;
		}
		//fabj(0,sum+1)
          //  printf("%d ",arr[j]);
		if ( arr[sum] )
		{
			result = true; break;
		}
	}
	delete [] arr;
	return result;
}

int main()
{
    int t,n,c[100],s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if ( n == 1 )
        {
            printf("NO\n");
            continue;
        }
        bzero(c,sizeof(c));
        s = 0;
        fabi(0,n)
        {
            scanf("%d", &c[i]);
            s += c[i];
        }
        if ((s % 2 == 0) && (checkSum(c, n, s / 2)))
		{
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
	return 0;
}
