#include <stdio.h>
#include <string.h>

int main()
{
	int t, dc[26], ds[26], i, r;
	char c[101];
	scanf("%d",&t);
	bzero(dc,sizeof(dc));
	bzero(ds,sizeof(ds));
	while(t--)
	{
		bzero(c,sizeof(c));
		scanf("%s",c);
		for(i = 0; c[i] != '\0'; ++i)
		{
			if (c[i] >= 'a')
				dc[c[i] - 'a'] = 1;
			else
				ds[c[i] - 'A'] = 1;
		}
	}
	r = 0;
	for (i=0;i<26;++i)
	{
		if (dc[i]) ++r;
		if (ds[i]) ++r;
	}
	printf("%d\n",r);
	return 0;
}
