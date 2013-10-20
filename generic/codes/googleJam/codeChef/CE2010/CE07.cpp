//Shifty nos

#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int t,d,sum,td;
	char ch;
	cin >> t;
	d = 0;
	ch = cin.get();
	while((ch = cin.get()) != -1){
		if(ch != '\n'){
			d += ch - '0';
			continue;
		}
		td = d;
		sum = 0;
		while(d > 0){
			sum += (d % 10);
			d /= 10; 
		}
		cout << (sum << td) << endl;
		d = 0;
	}
	return 0;
}
