#include <stdio.h>
#include <string.h>

int main(){
	int t, n, i, d, j, f, s;
	scanf("%d", &t);
	int arr[3001];
	int arr1[3001];
	while(t){
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		memset(arr1, 0, sizeof(arr));
		s = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &d);
			++arr[d];
			s += d;
		}
		if(s % n != 0)
			printf("-1");
		else{

			for(i = 0, j = 0; i <= n; ++i){
				if(arr[i] != 0){
					arr1[j++] = arr[i];
				}
			}
			f = 1;
			for(i = 0; i < j / 2; ++i){
				if(arr1[i] != arr1[j - 1 - i]){
					f = 0;
					break;
				}
			}
			if(f)
				printf("%d %d", j, j / 2);
			else
				printf("-1");
		}
		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
