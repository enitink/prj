#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d", &t);
	int r, i, j;
	int a[3][2];
	int flag;
	while(t){
		flag = 0;
		scanf("%d", &r);
		for(i = 0; i < 3; ++i){
			scanf("%d %d",&a[i][0], &a[i][1]);
			for(j = 0; j <= i; ++j)
				flag += (sqrt(pow((a[j][0] - a[i][0]),2) + pow((a[j][1] - a[i][1]),2)) < r) ? 1 : 0;
		}
		if(1 < flag)
			printf("yes\n");
		else
			printf("no\n");
		--t;
	}
	return 0;
}
