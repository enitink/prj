#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cmath>

using std::sqrt;

bool isPrime(long int n){
	long int i;
	for(i = 2; i <= sqrt(n); ++i){
		if( n%i == 0)
			return false;
	}
	return true;
}
int main(){
	int count = 0;
	cout << "0,";
	for(int i = 2; i <= 1000000; ++i)
		if(isPrime(i))
			cout << "1,";
		else
			cout << "0,";
	return 0;
}
