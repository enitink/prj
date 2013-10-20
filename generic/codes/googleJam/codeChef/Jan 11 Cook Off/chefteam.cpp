#include <iostream>

using namespace std;

int fact(unsigned long long n, unsigned long long k){
	unsigned long long i, j;
	unsigned long long ans = 1, temp = 1;
	if( (n - k) > (k)){
		for(i = n, j = k; i > n - k; --i, --j){
			ans *= i;
			temp *= j;
			if(0 == ans % temp){
				ans /= temp;
				temp = 1;
			}
			//cout << endl << ">>> " << i << " " << j;
		}
	}
	else{
		for(i = n, j = n - k; i > k; --i, --j){
			ans *= i;
			temp *= j;
			if(0 == ans % temp){
				ans /= temp;
				temp = 1;
			}
			//cout << endl << ">>> <<<<<" << i << " " << j;
		}
	}
		
	return ans;
}

int main(){
	int t;
	unsigned long long n, k;
	cin >> t;
	while(t){
		cin >> n >> k;
		cout << n << " " << k << endl;
		if(n && k)
			cout << fact(n, k);
		else
			cout << "0";
		--t;
		if(t)
			cout << endl;
	}
	return 0;
}
