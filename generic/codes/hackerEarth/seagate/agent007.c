#include <stdio.h>
#include <string.h>

#define SIZE 100000

int main()
{
    int t, i, c, n;
    char arr[SIZE];
    scanf("%d",&t);

   	while(t--)
   	{
		memset(arr,0,sizeof(arr));
   		scanf("%s", arr);
   		c = i = 0;
   		while( (arr[i] != '\n') && (arr[i] != 0)) 
   		{
   			if (arr[i] == '0')
   				c++;
   			++i;
   		}
   		scanf("%d", &n);
   		if ( ((n  * (n + 1)) / 2 ) % 2)
   			printf("%d\n", c);
   		else
   			printf("%d\n", i - c);
   	} 
    return 0;
}
