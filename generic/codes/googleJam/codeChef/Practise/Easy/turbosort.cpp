#include	<cstdio>
#include	<cstring>

#define		SIZE		1000000

int arr[SIZE];

int loc(int n, int i, int size){
	int mid = (i + size) / 2;
	if(i == size){
		if(arr[i] == n)
			return i + 1;
		else{
			if( arr[i] < n){
				return -1;
			}
			else
				return i;
		}
	}
	if(arr[mid] > n)
		if(arr[mid - 1] <= n)
			return mid;
		else
			size = mid - 1;
	else
		i = mid + 1;
 
	return loc(n, i , size);
}

int main(){
	int cases, l, i, data;
	scanf("%d", &cases);
	scanf("%d", &arr[0]);
//	printf("arr[0] %d", arr[0]);
	for(i = 0; i < cases - 1; ++i){
		scanf("%d", &data);
		l = i + 1;
		if(arr[i] > data){
			l = loc(data, 0, i - 1);
//			printf("%d %d\n",l, data);
			if(l == -1)
				l = 0;
			memmove(&arr[l + 1], &arr[l] , sizeof(int) * (i + 1));
		}
		arr[l] = data;
//		printf("\n-----------------------\n");
//		for(int j = 0; j < cases; ++j)
//			printf("%d\n", arr[j]);
//		printf("data %d arr[i] %d \n",data, arr[i]);
	}
	for(i = 0; i < cases; ++i)
		printf("%d\n", arr[i]);
	return 0;
}
