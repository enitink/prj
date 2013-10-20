#include	<iostream>
using std::cout;
using std::cin;
using std::endl;

#include	<cstring>
#include	<algorithm>
using std::max_element;

#define		SIZE		101

int main(){
	int testcases;
	int treeSize;
	int i,j;
	int arr[SIZE], tarr[SIZE], n;
	
	cin >> testcases;
	while(testcases){
		cin >> treeSize;
	
		memset(arr, 0, sizeof(arr));
		cin >> arr[0];
		for(i = 1; i < treeSize; ++i){
			memset(tarr, 0, sizeof(tarr));
			cin >> tarr[0];
			tarr[0] += arr[0]; 
			for(j = 1; j <= i; ++j){
				cin >> n;
				tarr[j] = ((arr[j] + n) > (arr[j - 1] + n)) ? arr[j] + n : arr[j - 1] + n;
			}
			memcpy(arr,tarr, sizeof(tarr));
		}
		cout << *(max_element(arr, arr + treeSize)) << endl;
		--testcases;
	}
	return 0;
}
