#include <stdio.h>

int main()
{
	int t,c=1,res,s,i,d,temp,x;
	char ch;
	scanf("%d", &t);
	while(t--)
	{
		temp = s = res = 0;
		scanf("%d%c",&s,&ch);
		for(i=0; i<=s; ++i)
		{
			scanf("%c",&ch);
			d = ch - '0';
			if (temp < i)
			{
				x = i - temp;
				res += x;
				temp += x;
			}
			temp += d;
		}
		printf("Case #%d: %d\n",c++, res);
	}
	return 0;
}
