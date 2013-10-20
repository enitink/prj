#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	int n,c;
	int vol[100];
	int mat[6][100];
	int i, j;
	int res;

	while(t){
		res = 0;
		scanf("%d %d", &n, &c);
		memset(vol, 0, sizeof(vol));
		memset(mat, 0, sizeof(mat));
		for(i = 0; i < n; ++i)
			scanf("%d", &vol[i]);
		sort(&vol[0], &vol[n]);

		for(i = 0; i < c; ++i)
			for(j = 0; j < 6; ++j)		
				scanf("%d", &mat[j][i]);
		for(i = 0; i < 6; ++i)
			sort(&mat[i][0], &mat[i][c]);

		for(i = 0; i < 6; ++i){
			if(c < n){
				for(j = 0; j < c; ++j){
					res += (vol[n - j - 1] < mat[i][c - j - 1]) ? vol[n - j - 1] : mat[i][c - j - 1];
					mat[i][c-j-1] -= vol[n-j-1];
				}
			}				
			else
				for(j = 0; j < c; ++j)
					res += (vol[n - j - 1] < mat[i][c - j - 1]) ? vol[n - j - 1] : mat[i][c - j - 1];

		}
		printf("%d",res);
		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
