#include <stdio.h>
#include <string.h>

int main()
{
	int t, d[26], s,i;
	char c[101];
	scanf("%d",&t);
	while(t--)
	{
		bzero(d,sizeof(d));
		bzero(c,sizeof(c));
		s = 0;
		scanf("%s",c);
		for(i = 0; c[i] != '\0'; ++i)
		{
			if (! d[c[i] - 'a']) s++;
			d[c[i] - 'a'] = 1;
		}
		if ( s == 26)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
