#include <stdio.h>
#include <cstring.h>
#define SIZE 10

char arr[SIZE][SIZE];
int a[SIZE][2];
int b[SIZE][2];
int c[SIZE][2];

int main(){
	int i, t, n, j, k, l;
	float nj, np;
	scanf("%d", &t);
	i = 1;
	while(t){
		memset(arr, 0, sizeof(arr));
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for(k = 0; k < n; ++k)
			for(j = 0; j < n; ++j){
				scanf("%d", arr[k][j]);
				if(arr[k] == '1'){
					++a[k][0];
					++a[k][1];
				}
				else
					if(arr[k] == '0')
					++a[k][1];
			}
		
		printf("Case #%d:", i++);
		for(k = 0; k < n; ++k){
			for(j = 0; j < n; ++j){
				if(arr[k][j] == '0'){
					b[j][0] = a[j][0] - 1;
				}
				else 
					if(arr[k][j] == '1'){
						b[j][0] = a[j][0];
					}
				b[j][1] = a[j][1] - 1;			
			}			
		}
		--t;
		if(t)
			printf("\n");
	}
	return t;
}
