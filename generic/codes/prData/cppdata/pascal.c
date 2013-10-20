#include<stdio.h>

int main(){
	int arr[6]={1,0,0,0,0,0};
	int i, j = 0, k, a = 0, b = 1;
	for(i = 0; i < 5; ++i){
		k = 0;
		while(arr[k] != 0){
			printf(" %d", arr[k]);
			++k;
		}
		printf("\n");
		j=1;
		do{
			arr[j] = a + b;
			a = b;
			b = arr[j];
			++j;
			
		}while(arr[j] != 0);
		arr[j] = 1;
	}
	return 0;
}