#include <stdio.h>

int main()
{
	int i = 2, c = 8;
	while ( c <= (2000 + 1999 + 1998))
	{
		printf("%d,", c);
		++i;
		c = i * i * i;
	}
	printf("\n%d",i - 2);
	return 0;
}
