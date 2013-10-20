//This was taking a lot of time to execute in cpp so.. i chose python... though i don't know.. y it's performing slow.. coz.. i have seen a lot may coders code not so much efficient like mine... :-(
#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	register int n, k , count = 0, data;
	cin >> n >> k;
	while(n){
		cin >> data;
		if((data % k) == 0)
			++count;
		--n;
	}
	cout << count;
}
