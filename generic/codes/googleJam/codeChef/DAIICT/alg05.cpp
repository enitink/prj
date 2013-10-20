#include <stdio.h>
#include <string.h>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
	int t, n , m, d;
	scanf("%d",&t);
	int arr[1001];
	int arr1[1001];
	while(t){
		memset(arr,0,sizeof(arr));
		scanf("%d %d", &n, &m);
		while(n--){
			scanf("%d",&d);
			arr[d]++;
		}
		while(m--){
			scanf("%d",&d);
			if(0 != arr[d]){
				--arr[d];
			}
			else{
				++arr1[d];
			}
		}
		d = accumulate(arr, arr + 1001, 0);
		printf("%d\n", d);
		--t;
	}
	return 0;
}
