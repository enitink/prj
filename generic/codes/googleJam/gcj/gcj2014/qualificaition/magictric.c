#include <stdio.h>
#include <string.h>

int main()
{
	int t,c = 1, ans, d, i,res,resnum;
	scanf("%d",&t);
	int row[16];
	while(t--)
	{
		scanf("%d", &ans);
		memset(row, 0, sizeof(row));
		for (i = 0; i < (ans - 1) * 4; ++i)
		{
			scanf("%d",&d);
		}
		for (i = 0; i < 4; ++i)
		{
			scanf("%d", &d);
			row[d-1] = 1;
		}
		for (i = 0; i < (4 - ans) * 4; ++i) 
		{
			scanf("%d",&d);
		}
		scanf("%d", &ans);
		for (i = 0; i < (ans - 1) * 4; ++i)
		{
			scanf("%d",&d);
		}
		resnum = 0;
		for (i = 0; i < 4; ++i)
		{
			scanf("%d", &d);
			if (row[d-1] == 1)
			{
				res = d;
				++resnum;
			}
		}
		for (i = 0; i < (4 - ans) * 4; ++i) 
		{
			scanf("%d",&d);
		}
		switch (resnum)
		{
		case 0:
			printf("Case #%d: Volunteer cheated!\n",c);
			break;
		case 1:
			printf("Case #%d: %d\n", c, res);
		break;
		default:
			printf("Case #%d: Bad magician!\n",c);
		break;
		}
		++c;
	}
}
