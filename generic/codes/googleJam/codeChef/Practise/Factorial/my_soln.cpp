#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	long int noofcases, data, result, power;
	int i;
	cin >> noofcases;

	while(noofcases){
		cin >> data;
		result = 0;
		power = 5;
		while(data >= power){
			result += data / power;
			++i;
			power *= 5;
		}
		--noofcases;
		cout << result << endl;
	}
	return 0;
}
