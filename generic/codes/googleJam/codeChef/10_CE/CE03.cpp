// the ruins of foolland...

#include	<stdio.h>

int main(){
	int t, d, b = 15, td[32], i, j;
	scanf("%d", &t);
	while(t){
		scanf("%d", &d);
		i = 0;
		while(d > 0){
			td[i++] = (d & b);
			if(td[i - 1] != 9)
				td[i - 1] %= 9;
			d = d >> 4;
		}
		for(j = i - 1; j >= 0; --j)
			printf("%c",64 + td[j]);
		printf("\n");
		--t;
	}
	return 0;
}
