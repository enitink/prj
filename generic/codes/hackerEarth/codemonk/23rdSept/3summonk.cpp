#include <cstdio>
#include <algorithm>

#define SIZE 500

using namespace std;

int main()
{
    int t,n,i,arr[SIZE],c,tc,j,k,l;
    double res;
    int cubeArr[]= {8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832};
    
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
    	c = (n * (n-1) * (n-2)) / (6);
    	tc = 0;
    	for(i = 0; i < n; ++i)
    	{
    		scanf("%d", &arr[i]);
    	}
    	sort(arr, arr + n);
    	for (i = 0; i < 17; ++i)
    		for (j = 0; j < n; ++j)
    		{
    			if ( arr[j] >= cubeArr[i])
    				continue;
    			for(k = j + 1; k < n; ++k)
    			{
    				if ( j == k )
    					continue;
    				if ( arr[j] + arr[k] >= cubeArr[i])
    					break;
    				for(l = k + 1; l < n; ++l)
    				{
    					if ( (l == j) || ( l == k ) )
    						continue;
    					if ( arr[j] + arr[k] + arr[l] == cubeArr[i])
    						++tc;
    					else if (arr[j] + arr[k] + arr[l] > cubeArr[i])
    						break;
    				}
    			}
    		}
    	res = (1.0 * tc) / (1.0 * c);
    	printf("%.9f\n",res);
    }
    return 0;
}
