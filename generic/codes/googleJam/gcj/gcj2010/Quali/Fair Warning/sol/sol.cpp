#include	<iostream>
#include	<gmp.h>

using namespace std;

int main(){
	int c, i, n, j;
	mpz_t arr[1000];
	cin >> c;
	for(i = 0; i <= c; ++i){
		cin >> n;
		for(j = 0; j < n; ++j){
			cin >> arr[j];
			cout << arr[j] << " ";
		}
		cout << endl;
		--c;		
	}
	return 0;
}
