#include <stdio.h>

int main()
{
	int t, caseno = 1;
	double c,f,x,ans;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		
		printf("Case #%d: %3.7lf\n",caseno, ans);
		++caseno;
	}
	return 0;
}
