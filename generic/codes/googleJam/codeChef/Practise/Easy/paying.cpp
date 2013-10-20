#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>

#define		SIZE	20

int main(){
	int cases, n, m, i, arr[SIZE], flag, sum, j;
	cin >> cases;

	while(cases){
		cin >> n >> m;
		memset(arr, 0, sizeof(arr));

		for(i = 0; i < n; ++i){
			cin >> arr[i];
		}
		for(i = 1; i < (2 << n); ++i){
			sum = 0;
			flag = 0;
			for(j = 0; j < n; ++j){
				if((i & (1 << j)) > 0)
					sum += arr[j];
			}
			if(sum == m){
				flag = 1;
				break;
			}
			if(flag == 1)
				break;
		}
		cout << ((flag)? "Yes" : "No") << endl;
		--cases;
	}
	return 0;
}
