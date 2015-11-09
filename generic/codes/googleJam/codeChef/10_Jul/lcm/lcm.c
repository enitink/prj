#include	<stdio.h>

int main(){
	int t, a, b, max, i, min;
	long int sum, diff, temp, doit;
	long int result;
	int modulo = 1 << 30;
	scanf("%d", &t);
	while(t){
		scanf("%d %d", &a, &b);
		min = (a >= b) ? a : b;
		max = (a >= b) ? b : a;
//		printf("%d %d\n", max, min);
		sum = ( min * ( min + 1 ) ) / 2;
//		printf("%ld\n", sum);
		result = sum % modulo;
//		printf("%ld\n", result);
		for(i = 2; i <= max; ++i){
			temp = min / i;
			temp = (temp * (temp + 1) / 2) * i;
//			printf("%ld\n", temp);
			doit = 0;
			//if( (i % min == 0) || (min % i == 0) )
			//		doit = i;
			
			diff = (sum - temp) * i + temp - doit;
			result = (result + diff) % modulo;
//			printf("%ld\n", diff);
		}
		printf("%ld\n", result);
		--t;
	}
	return 0;
}
