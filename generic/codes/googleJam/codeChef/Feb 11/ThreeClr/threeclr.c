#include <stdio.h>
#include <string.h>

int matrix[500][501];

void resetMatrix(int r, int c, int n){
	int i;
	for(i = c; i < n; ++i){
		matrix[r][i] |= matrix[c - 1][i];
	}
	return;
}

void print(int n){
	int i, j;
	for(i = 0; i < n; ++i){
		for(j = 0; j <= n; ++j)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main(){
	int t;
	int n, m;
	int u, v;
	int i, j;
	int f;
	int r;
	scanf("%d", &t);

	while(t){
		memset(matrix, 0, sizeof(matrix));
		r = 1;
		f = 0;
		scanf("%d %d", &n, &m);

		while(m){
			scanf("%d %d", &u, &v);
			++matrix[u-1][v-1];
			++matrix[v-1][u-1];
			--m;
		}
		for(i = 0; i < n; ++i){
			if(0 != matrix[i][500]){
				continue;
			}
			else{
				++f;
				matrix[i][500] = r;
			}
			for(j = i + 1; j < n; ++j){
				if(0 != matrix[j][500])
					continue;
				if(1 != matrix[i][j]){
					matrix[j][500] = r;
					++f;
					resetMatrix(i,j + 1, n);
				}
			}
			++r;
			if(f == n)
				break;
		}
		for(i = 0; i < n; ++i){
			printf("%d", matrix[i][500]);
			if(i != n-1)
				printf(" ");
		}
		--t;
		if(t)
			printf("\n");
	}
}
