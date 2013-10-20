//try it later on.. am doing a mistake of not considering for the same slot..

#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);

	int m, n, r;
	int i, j, d;
	int arr[100][5000];
	while(t){
		scanf("%d %d", &m, &n);
		r = 0;
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j)
				scanf("%d", &arr[i][j]);
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j){
				scanf("%d", &d);
				arr[i][j] = (arr[i][j] < d) ? arr[i][j] : d;
			}
		for(i = 0; i < m; ++i)
			for(j = 0; j < n; ++j){
				scanf("%d", &d);
				arr[i][j] *= d;
			}
		for(i = 0; i < m; ++i)
			r += *max_element(&arr[i][0], &arr[i][m + 1]);
		printf("%d", r);
		--t;
		if(t)
			printf("\n");
	}	
	return 0;
}
