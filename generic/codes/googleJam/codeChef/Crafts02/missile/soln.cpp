#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>
#define		fun(X1, Y1, X2, Y2, Y)		((((Y - Y1)*(X2 - X1)) / ( Y2 - Y1)) + (X1))

int arr[20][3];
void sort(int n){
	int i,j, temp;
	for(i = 0; i < n; ++i){
		for(j = 0; j < n - i - 1; ++j){
			if(arr[j][0] > arr[j+1][0]){
				temp = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = temp;
				temp = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = temp;
				temp = arr[j][2];
				arr[j][2] = arr[j + 1][2];
				arr[j + 1][2] = temp;
			}
		}
	}
}

int main(){
	int t, w, n, k, flag;
	float d, i , j;
	cin >> t;
	while(t){
		cin >> w;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		flag = 1;
		for(k = 0; k  < n; ++k){
			cin >> arr[k][0] >> arr[k][1] >> arr[k][2];
			if(arr[k][1] == arr[k][2]){
				flag = 0;
			}
		}
		sort(n);
		for(i = arr[n-1][1]; i <= arr[n-1][2]; i += 1){
			if(flag == 0)
				break;
			for(j = arr[0][1]; j <= arr[0][2]; j+=1){
				flag = 0;
				for(k = 1; k < n - 1; ++k){
					d = fun((j * 1.0), arr[0][0], (i * 1.0), arr[n - 1][0], arr[k][0]);
//					cout << endl << "D arr[K] K : " << d << " " << arr[k][1] << " " << k;
					if((d >= arr[k][1]) && (d <= arr[k][2])){
//						cout << endl << "inside D arr[K] : " << d << " " << arr[k][1];
						flag = 1;
					}
					else{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
					break;
			}
			if(flag == 1)
				break;
		}
		cout << ((flag)? "Yes" : "No") << endl;
		--t;
	}
	return 0;
}
