#include <stdio.h>

int main()
{
	char alpha[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char ch = ' ';
	int t, i;
	
	scanf("%d", &t);
	scanf("%c", &ch);
	for (i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		while(1)
		{
			scanf("%c", &ch);
			if(ch == '\n')
				break;
			if(ch == ' ')
			{
				printf(" ");
			}
			else
				printf("%c", alpha[ch - 'a']);
		}
		printf("\n");
	}

	return 0;
}
