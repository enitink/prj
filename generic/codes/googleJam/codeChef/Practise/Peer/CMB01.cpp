/*
sum of reverse no... and then.. reversing it back again....
*/

#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	int t, a, b, ra, rb;
	cin >> t;
	while(t){
		cin >> a >> b;
		ra = 0;
		rb = 0;
		do{
			ra = (ra * 10) + (a % 10);		
		}while(a /= 10);
		do{
			rb = (rb * 10) + (b % 10);		
		}while(b /= 10);
		ra += rb;
		do{
			b = (b * 10) + (ra % 10);		
		}while(ra /= 10);
		cout << b << endl;
		--t;
	}
	return 0;
}
