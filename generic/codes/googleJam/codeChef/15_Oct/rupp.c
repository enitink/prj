#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define UI unsigned long int

int main()
{
	UI t,n,i,j,rt,temp,flag,x;
	scanf("%lu",&t);
	while(t--)
	{
		scanf("%lu",&n);
		while (!(n&1))
		{
				n>>=1;
				//printf("%lu \n",n);
		}

		for ( i = 3; i <= sqrt(n); i = i+2)
		{ 
				flag=0;
				while (n%i == 0)
				{
						n /= i;
						flag=2;
				}
				//printf("%lu n=%lu\n",i,n);
				if((i-1)%4==0 && flag==2)
				{flag=1;break;}
		}
		if (n > 2 && (n-1)%4==0)
		{flag=1;}

		if(flag==1)
				printf("YES\n");
		else 
				printf("NO\n");
	}
	return 0;

}
