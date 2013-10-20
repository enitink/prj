#include	<iostream>

using namespace std;

int main(){
	int n = 16385;
	while(n > 0){
		cout << " " << (n & 1);
		n = n >> 1;
	}
	return 0;
}
