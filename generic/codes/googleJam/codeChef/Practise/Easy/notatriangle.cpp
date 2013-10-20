#include	<iostream>
using std::cin;
using std::cout;
using std::endl;
 
#include	<cstring>
 
#include	<algorithm>
using std::sort;
 
#define 	SIZE	2000
 
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
	int n, i, count, l, j;
 
	while(true){
		cin >> n;
		if(n == 0)
			break;
		count = 0;
		memset(arr,0,sizeof(arr));
		for(i = 0; i < n; ++i){
			cin >> arr[i];
		}
		sort(arr,arr + n);
		for(i = 0; i < n - 2; ++i){
			for(j = i + 1; j < n - 1; ++j){
				l = loc(arr[i] + arr[j], j + 1, n - 1);
				l = (l == -1)? n : l;
				count += (n - l);
			}
		}
		cout << count << endl;
	}
	
	return 0;
} 
