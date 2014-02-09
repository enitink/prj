#include <stdio.h>
#include <string.h>

#define SSIZE 10010 
int main()
{
	int t,i,j,cL[26],cU[26],cD[10],res;
	char c[SSIZE],d[SSIZE];

	scanf("%d",&t);
	while(t--)
	{
		bzero(cL,sizeof(cL));
		bzero(cU,sizeof(cU));
		bzero(cD,sizeof(cD));
		res = 0;
		scanf("%s%s",c,d);
		for(j=0; c[j] != '\0'; ++j)
		{
			if ( c[j] >= 'a' )
				++cL[c[j] - 'a'];
			else if ( c[j] >= 'A' )
				++cU[c[j] - 'A'];
			else
				++cD[c[j] - '0'];
		}
		for(j=0; d[j] != '\0'; ++j)
		{
			if ( d[j] >= 'a' )
			{ 
				if(cL[d[j] - 'a'] > 0)
				{
			 		res++;
					cL[d[j] - 'a']--;
				} 
			}
			else if ( d[j] >= 'A' )
			{ 
				if(cU[d[j] - 'A'] > 0)
				{
					res++; 
					cU[d[j] - 'A']--;	
				}
			}
			else
			{
				if(cD[d[j] - '0'] > 0)
				{
					res++;
					cD[d[j] - '0']--;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
