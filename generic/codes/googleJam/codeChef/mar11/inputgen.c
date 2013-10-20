#include <stdio.h>

int main(){
	printf("5\n");
	int t = 5, i, j, n, k;
	scanf("%d %d", &n, &k);
	while(t){
		printf("%d %d\n", n, k);
		/*for(i = 0; i < n / k; ++i)
			for(j = 100000; j < 100000 + k; ++j)
				printf("%d ", j);*/
		for(i = 0; i < 26000; ++i)
			printf("%d ", i);
		for(i = 0; i < 24000; ++i)
			printf("%d ", 100000000);
		printf("\n");
		--t;
	}
	return 0;
}
