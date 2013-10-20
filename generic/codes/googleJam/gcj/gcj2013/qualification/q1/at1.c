#include <stdio.h>

int main()
{
	int T, r, c, caseNo = 1;
	int e, hT, dDT, dUT, hO, dDO, dUO;
	char ch;
	int won;
	scanf("%d", &T);

	while(T)
	{
		e = dDT = dUT = dDO = dUO = 0;
		for (r = 0; r < 4; )
		{
			hT = hO = 0;
			won = 0;
			for (c = 0; c < 4; )
			{
				scanf("%c", &ch);
				printf("1. %c", ch);
				if ( !( (ch == 'T') || (ch == 'X') || (ch == 'O') || (ch == '.')) )
					continue;
				if (ch == '.')
				{
					printf ("++ at . ch = %c\n", ch);
					++e;
				}
				else if (ch == 'X')
				{
					printf ("++ at X ch = %c\n", ch);
					++hT;
					if (r == c) { ++dDT; }
					if ( 3 == (r + c) ) { ++dUT; }
				}
				else if (ch == 'O')
				{
					printf ("++ at O ch = %c\n", ch);
					++hO;
					if (r == c) { ++dDO; }
					if ( 3 == (r + c) ) { ++dUO; }
				}
				else
				{
					printf ("++ at T ch = %c\n", ch);
					++hT; ++hO;
					if (r == c) { ++dDT; ++dDO; }
					if ( 3 == (r + c) ) { ++dUT; ++dUO; }
				}
				if ( hT == 4 )
				{
					printf("1. Case #%d: X won\n", caseNo++);
					won = 1;
					break;
				}
				else if (hO == 4)
				{
					printf("2 .Case #%d: O won\n", caseNo++);
					won = 1;
					break;
				}
				++c;
			}
			if ( won )
				break;
			if (dUT == 4 || dDT == 4)
			{
				printf("3. Case #%d: X won\n", caseNo++);
				won = 1;
				break;
			}
			else if (dUO ==  4 || dDO == 4)
			{
				printf("5. Case #%d: O won\n", caseNo++);
				won = 1;
				break;
			}

			++r;
		}
		if (won == 0)
		{
			if (e)
				printf("Case #%d: Game has not completed\n", caseNo++);
			else
				printf("Case #%d: Draw\n", caseNo++);
		}
		T--;
	}
	return 0;
}
