#include <stdio.h>

int main(){
	int t, a, b, c, r, i, tr, max;
	scanf("%d", &t);
	while(t){
		r = 0;
		scanf("%d %d %d", &a, &b, &c);
		max = a*100 + b;
		for(i = 0; i <= 10000; ++i){
			if(a * 100 + b <= c)
				break;
			b -= c;
			//printf("%d %d %d\n", a, b,max);			
			if(b < 0){
				b += 100;
				--a;
			}
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			tr = a*100 + b;
			//printf("%d %d %d\n", a, b, max);
			if(tr > max){
				r = i + 1;
				max = tr;
			}
			else
				if(tr == max)
					break;	
		}		
		--t;
		printf("%d",r);
		if(t)
			printf("\n");
	}
	return 0;
}
