#include<stdio.h>

int main(){
	int arr[6]={1,0,0,0,0,0};
	int i, j = 0, k, a = 0, b = 1, t;
	for(i = 0; i < 5; ++i){
		k = 0;
		while(arr[k] != 0){
			printf(" %d", arr[k]);
			++k;
		}
		printf("\n");
		j=0;
		a = arr[0];
		b = arr[1];
		while(arr[j] != 0){
			a += b;
			t = b;
			b = arr[j];
			++j;
			arr[j] = a;
			a = t;			
			++j;
		}
		arr[j] = 1;
	}
	return 0;
}
