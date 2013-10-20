#include	<cstdio>
#include	<cstring>

#define		SIZE		1000000

int arr[SIZE];

int main(){
	int cases, l, i, data, mid, j, size;
	scanf("%d", &cases);
	scanf("%d", &arr[0]);
	for(i = 0; i < cases - 1; ++i){
		scanf("%d", &data);
		l = i + 1;
		if(arr[i] > data){
			size = i - 1;
			j = 0;
			l = -1;
			while(true){
				mid = (j + size) / 2;
				if(j == size){
					if(arr[j] == data){
						l = j + 1;
						break;
					}
					else{
						if( arr[j] < data){
							l = -1;
							break;
						}
						else{
							l = j;
							break;
						}
					}
				}
				if(arr[mid] > data)
					if(arr[mid - 1] <= data){
						l = mid;
						break;
					}
					else
						size = mid - 1;
				else
					j = mid + 1;
			}
			if(l == -1)
				l = 0;
			memmove(&arr[l + 1], &arr[l] , sizeof(int) * (i + 1));
		}
		arr[l] = data;
		cout << a[i];
	}
	for(i = 0; i < cases; ++i)
		printf("%d\n", arr[i]);
	return 0;
}
