#include <stdio.h>

int main(){
	int t, n, a, b, c, i, j;
	long long res;
	scanf("%d", &t);
	while(t){
		res = 0;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		for(i = 0; i <= ((a < n) ? a : n); ++i)
			for(j = 0; j <= (((n-i) < b)? n - i : b); ++j)
				res += 1 + (((n - i - j) < c) ? (n - i - j) : c);
		printf("%lld", res);
		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
