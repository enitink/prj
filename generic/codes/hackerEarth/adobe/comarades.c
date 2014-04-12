#include <stdio.h>
#include <string.h>

int main()
{
	int t,n,h,b, sol[100000],i,j,lev[100000],l,ch,maxl;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i < n; ++i)
			scanf("%d",&sol[i]);
		maxl = 0;
		memset(lev,0,sizeof(lev));
		for(i=0;i < n; ++i)
		{
			if ( sol[i] == 0)
				continue;
			ch = sol[i];
			l = 0;
			while ( sol[ch - 1] )
			{
				++l;
				ch = sol[ch-1];
			}
			if ( l > maxl)
				maxl = l;
			++lev[l]; 
		}
		h = b = 0;
		for (i = 0; i <= maxl; ++i)
		{
			h += lev[i];
			if (i > 0)
			{
				for (j = i - 1; j >= 0; --j)
					h += (lev[i]* lev[j]);
			}
			b += (lev[i] - 1);
		}
		printf("%d %d\n",h,b);
	}
	return 0;
}
