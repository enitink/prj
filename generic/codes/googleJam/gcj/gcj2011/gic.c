#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(){
	int t, c, d, n, i, j, k;
	char ch, arrRep[1][3], arrOpp[1][2], res[SIZE];
	
	scanf("%d", &t);
	i = 1;

	while(t){
		memset(res, 0, sizeof(res));
		scanf("%d", &c);
		for(j = 0; j < c; ++j){
			scanf("%c",&ch);
			scanf("%c%c%c",&arrRep[j][0],&arrRep[j][1],&arrRep[j][2]);

		}
		//for(j = 0; j < c; ++j)
		//	printf("\n%c %c %c",arrRep[j][0], arrRep[j][1],arrRep[j][2]);
		scanf("%d", &d);
		for(j = 0; j < d; ++j){
			scanf("%c",&ch);
			scanf("%c%c",&arrOpp[j][0], &arrOpp[j][1]);
		}
		//for(j = 0; j < c; ++j)
		//	printf("\n%c %c",arrOpp[j][0], arrOpp[j][1]);

		scanf("%d", &n);
		scanf("%c",&ch);
		scanf("%c", &res[0]);
		for(j = 1; j < n; ++j){
			scanf(%c,&ch);
			
			for(k = 0; k < c; ++k){
				if(arrRep[k][0] == 
			}
		}

		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
