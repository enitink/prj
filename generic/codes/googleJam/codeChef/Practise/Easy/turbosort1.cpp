#include	<cstdio>
#include	<cstring>

#define		SIZE		1000001

int arr[SIZE];

int main(){
	int cases, data, i, j;
	scanf("%d", &cases);
	i = cases;
	memset(arr, 0 , sizeof(arr));
	while(cases){
		scanf("%d",&data);
		arr[data] += 1;
		--cases;
	}
	j = 0;		
	while(i){
		while(arr[j] > 0){
			printf("%d\n", j);
			--arr[j];
			--i;
		}
		++j;
	}
	return 0;
}
