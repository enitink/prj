#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	long int cases, data, n;
	cin >> cases;
	
	while(cases){
		n = 2;
		cin >> data;
		while(n <= data)
			n = n << 1;
		if(n != data)
			n = n >> 1;
		cout << n << endl;
		--cases;
	}
}
