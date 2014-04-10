#include <stdio.h>
#include <string.h>

int main()
{
	int k,i,tg = 1,len,j,tk;
	char s[2][1010];
	char st[1010];
	memset(s[0],0, 1010);
	memset(s[1],0, 1010);
	scanf("%d",&k);
	tk = k;
	scanf("%s",s[0]);
	memcpy(st,s,1010);
	len = strlen(s[0]);
	while(k--)
	{
		tg = tg ^ 1;
		for(i = 0, j = 0; i <= len / 2; ++i, j += 2)
		{
			if (j >= len)
				--j;
			s[(tg + 1) % 2][i]  =  s[tg][j];
		}
		for(i = len - 1, j = 1; i > len / 2; --i, j+=2)
			s[(tg + 1) % 2][i] = s[tg][j];
		if (strcmp(s[(tg+1)%2], st)	== 0)
		{
			k = tk % (tk - k);
		}
	}
	printf("%s\n", s[(tg+1)%2]);
	return 0;
}
