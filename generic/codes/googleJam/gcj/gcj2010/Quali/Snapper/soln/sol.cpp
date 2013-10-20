#include	<iostream>
#include	<cstring>
#include	<numeric>

using namespace std;

int main(){
	int i, j;
	int t;
	int n, k, result;
	bool arr[10];
	cin >> t;
	while(t){
		cin >> n >> k;
		memset(arr, 0, sizeof(arr));
		for(i = 0; i < k; ++i){
			j = 0;
			while(true == arr[j])
				j++;
			memset(arr, 0, sizeof(bool) * (j + 1));
			arr[j] = 1;
			//cout << endl << "step : " << i + 1 << " : ";
			//for(j = 0; j < n; ++j)
			//	cout << arr[j] << " ";
		}
		result = accumulate(&arr[0], &arr[n], 0);
		//cout << endl << result;
		if(result == n)
			cout << endl << "ON";
		else
			cout << endl << "OFF";
		--t;
	}
	return 0;
}
