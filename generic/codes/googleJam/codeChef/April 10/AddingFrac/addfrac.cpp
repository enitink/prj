#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>

#include	<iomanip>

using std::fixed;
using std::setprecision;

int gcd(int a, int b){
	return (b == 0)? a : gcd(b, a % b);
}

int main(){
	int t, n, i, last, j, gc;
	char ch;
	bool flag;
	float list[100100][2], a , b, c, d;
	
	cin >> t;
	while(t){
		cin >> n;
		cin.get();
		memset(list, 0, sizeof(list));
		i = 1;
		last = 1;
		while(n){
			flag = false;
			a = 0;
			b = 0;
			while( ( ch = cin.get() ) != '\n'){
				if(ch == '/'){
					flag = true;
					continue;
				}
				else{
					if(flag == true)
						b = (b * 10) + (ch - '0');
					else
						a = (a * 10) + (ch - '0');
				}
			}
			if(i == 1){
				list[i][0] = a;
				list[i][1] = b;
				--n;
				++i;
				continue;
			}
			if((list[i - 1][0] / list[i - 1][1]) <= ((list[i - 1][0] + a) / (list[i - 1][1] + b))){
				list[i][0] = list[i - 1][0] + a;
				list[i][1] = list[i - 1][1] + b;
			}
			else{
				list[i][0] = a;
				list[i][1] = b;
				for(j = last - 1; j < i - 1; ++j){
					a = list[i - 1][0] - list[j][0];
					b = list[i - 1][1] - list[j][1];
					gc = gcd(a,b);
					a /= gc;
					b /= gc;
					cout << fixed << setprecision(0) << a << "/" << b << endl;
				}
				list[i - 1][0] = 0;
				list[i - 1][1] = 0;
				last = i;
 			}
			++i;
			--n;
		}
		for(j = last - 1; j < i - 1; ++j){
			a = list[i - 1][0] - list[j][0];
			b = list[i - 1][1] - list[j][1];
			gc = gcd(a,b);
			a /= gc;
			b /= gc;
			cout << fixed << setprecision(0) << a << "/" << b << endl;
		}
		cout << endl;
		--t;
	}
	return 0;
}
