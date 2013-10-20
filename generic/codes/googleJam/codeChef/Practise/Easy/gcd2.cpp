#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int t, a, b, i;
	char st[252];
	cin >> t;
	while(t--){
      		cin >> a;
		cin >> st;
      		if(0 == a){
      			if(t)
		      		cout << endl;
      			continue;
      		}
      		else
	      		if(1 == a){
	      			cout << "1";
	      		if(t)
	      			cout << endl;
	      		continue;
	      	}
      		b = 0;
		i = 0;
      		while(st[i] != '\0'){
      			b = (b * 10 + (st[i] - '0')) % a;
			++i;
      		}
      		if(0 == b)
	      		cout << a;
      		else
      			cout << gcd(a,b);
		if(t)
			cout << endl;
	}
	return 0;
} 
