#include <stdio.h>
#include <string.h>
#include <math.h>

#define memsetZero(x)	memset(x, 0, sizeof(x))
#define memsetOne(x)	memset(x, 1, sizeof(x))
#define fol(x,y)	for(x = 0; x < y; ++x)
#define folR(x,y,z)	for(x = y; x < z; ++x)

long long int gcd(long long int a, long long int b){
	return((b == 0)? a : gcd(b, a % b));
}
long long int lcm(long long int a, long long int b){
	return a * b / gcd(a,b);
}

int main(){
	int i, t, n, fl;
	long long j, l, h, m;
	long long int d, d1;
	scanf("%d", &t);
	i = 1;
	while(t){
		scanf("%d %lld %lld", &n, &l, &h);
		scanf("%lld", &d);
		m = d;
		fol(j,n - 1){
			scanf("%lld", &d1);
			if(d < d1)
				m = d1;
			d = lcm(d, d1);
		}
		printf("Case #%d: ", i++);
		
		if((d != m) && (d > h))
			printf("NO");
		else
		if((d >= l) && (d <= h))
			printf("%lld",d);
		else{
			folR(j,l,h+1){
				fl = 0;
				if(d % j == 0){
					fl = 1;
					d = j;
					break;
				}
			}
			if(fl)
				printf("%lld",d);
			else
				printf("NO");
		}
		--t;
		if(t)
			printf("\n");
	}
	return t;
}
