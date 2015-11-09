#include <stdio.h>
 
typedef unsigned long long ULL;
 
ULL gcd(ULL a,ULL b)
{
	ULL c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}
 
ULL bin(ULL n,ULL k)
{
	if(n<k) return 0;
	if(k>n-k) k=n-k;
	ULL p=1;
	ULL i;
	for(i=1;i<=k;i++)
	{
		ULL d=gcd(p,i);
		p/=d;
		p*=(n-i+1)/(i/d);
	}
	return p;
}
 
int main()
{
	int TST;
	scanf("%d",&TST);
	while(TST)
	{ 
		ULL n,k;
		scanf("%llu %llu",&n,&k);
		ULL ans=bin(n,k);
		--TST;
		printf("%llu",ans);
		if(TST)
			printf("\n");
	}
	return 0;
}
 
