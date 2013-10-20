//by enitink
#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<cmath>
#include 	<numeric>

using namespace std;

int main(){
	int t, i, l, p, c;
	int result;
	cin >> t;
	for(i = 1; i <= t; ++i){
		cin >> l >> p >> c;
		result = 0;
		while(true){
			if(p <= (l * c)){
				++result;
				break;
			}
			p = p / c + 1;
			l = l * c;
			++result;
		}
		cout << endl << "Case #" << i << ": " << result;
	}
	return 0;
}
