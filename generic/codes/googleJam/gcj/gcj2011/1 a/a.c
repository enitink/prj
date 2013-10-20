#include <stdio.h>

int main(){
	int t, n, d, g, i, j, flag;
	scanf("%d", &t);
	i = 1;
	while(t){
		scanf("%d %d %d", &n, &d, &g);
		printf("Case #%d: ", i++);
		if(d < g)
			printf("Broken");
		else{
			flag = 0;
			for(j = 1; j < n; ++j){
				if(((j * d) % 100)){
					flag = 1;
					break;
				}
			}
			if(flag)
				printf("Possible");
			else
				printf("Broken");
		}
		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
