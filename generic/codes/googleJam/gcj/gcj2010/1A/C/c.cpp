#include	<iostream>

using namespace std;

bool isTrue(int a, int b){
	if(a > b){
		a += b;
		b = a -b;
		a -= b;
	}
	if( a == b)
		return false;
	if((b % a) == 0)
		return true;
	if( (b - (a + 1)) == 0)
		return false;
	if( a % (b % a) == 0)
		return true;
	if( 0 == ( (b - (1 + a) ) % a) )
		return true;
	else 
		return false;
}
int main(){
	int t, i, a1, a2, b1, b2, j, k, count;
	cin >> t;

	for(i = 1; i <= t; ++i){
		cin >> a1 >> a2 >> b1 >> b2;
		count = 0;
		for(j = a1; j <= a2; ++j){
			for(k = b1; k <= b2; ++k){
				if(isTrue(j, k)){
					++count;
				}
			}
		}
		cout << "Case #" << i << ": "<< count << endl;
	}
	return 0;
}
