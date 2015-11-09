#include <stdio.h>

int main()
{
	int t, d, r, res;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &d);
		r = d % 7;
		res = -1;
		switch(r)
		{
		case 0:
			res = d;
			break;
		case 1:
			if (d > 8)
				res = d - 8;
			break;
		case 2:
			if (d > 16)
				res = d - 16;
			break;
		case 3:
			if ( d > 24 )
				res = d - 24;
			break;
		case 4:
			if (d > 4 )
				res = d - 4;
			break;
		case 5:
			if ( d > 12 )
				res = d - 12;
			break;
		case 6:
			if ( d > 20 )
				res = d - 20;
			break;
		}		
		if (res == -1 )
		{
			r = d % 4;
			if( r == 0 )
				res = 0;
		}
		printf("%d\n", res);
	}

	return 0;
}
