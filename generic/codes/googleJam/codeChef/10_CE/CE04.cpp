//Spyrograph

#include	<stdio.h>

int main(){
	int t, i ,j, k;
	int mat[4][4];
	scanf("%d", &t);
	while(t){
		for(i = 0; i < 4; ++i)
			for(j = 0; j < 4; ++j)
				scanf("%d", &mat[i][j]);
		for (i = 3, j = 0; i > 0; i--, j++) {
              		for (int k = j; k < i; k++) printf("%d\n",mat[j][k] * 4);
		        for (int k = j; k < i; k++) printf("%d\n",mat[k][i] * 4);
              		for (int k = i; k > j; k--) printf("%d\n",mat[i][k] * 4);
              		for (int k = i; k > j; k--) printf("%d\n",mat[k][j] * 4);
       		}     
		--t;
	}
	return 0;
}
