#include <stdio.h>

int run(int n, char* cu)
{
	int c[26] = {}; 
	int i = 0, nc = 0, r = 0;
	while ( cu[i] != '\0' )
	{
		if ( c[cu[i] - 'A'] == 1)
		{
			c[cu[i] - 'A'] = 0;
			--nc;
		}
		else
		{
			if ( nc < n )
			{
				if ( c[cu[i] - 'A'] != 2 )
				{
					c[cu[i] - 'A'] = 1;
					++nc;
				}
				else
				{
					c[cu[i] - 'A'] = 0;
				}
			}
			else
			{
				if (c[cu[i] - 'A'] == 0)
				{
					c[cu[i] - 'A'] = 2;
					++r;
				}
				else
				{
					c[cu[i] - 'A'] = 0;
				}
			}
		}
		++i;
	}
	return r;
}

int main()
{
	printf("%d\n", run(2, "ABBAJJKZKZJJ"));
	printf("%d\n", run(3, "GACCBDDBAGEE"));
	printf("%d\n", run(3, "GACCBGDDBAEE"));
	printf("%d\n", run(1, "DAABCCDBEE"));
	return 0;
}
