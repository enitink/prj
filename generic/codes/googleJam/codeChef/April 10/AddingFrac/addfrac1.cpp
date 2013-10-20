#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<cstring>

int gcd(int a, int b){
	return (b == 0)? a : gcd(b, a % b);
}

int main(){
	int t, n, i, last, j, gc;
	char ch;
	bool flag;
	int list[100001][2], a , b;
	
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
			if(i == last){
//				cout << endl << "meeeeee ";
				list[i][0] = a;
				list[i][1] = b;
				--n;
				++i;
				continue;
			}				
			if((list[i - 1][0] / list[i - 1][1]) <= ((list[i - 1][0] + a) / (list[i - 1][1] + b))){
//				cout << endl << "meeeeee ";
				list[i][0] = list[i - 1][0] + a;
				list[i][1] = list[i - 1][1] + b;
//				cout << list[i][0] << "/" << list[i][1] << endl;
			}
			else{
				list[i][0] = 0;
				list[i][1] = 0;
				list[i+1][0] = a;
				list[i+1][1] = b;
//				cout << last << " " << i << endl;
				for(j = last - 1; j < i - 1; ++j){
					a = list[i - 1][0] - list[j][0];
					b = list[i - 1][1] - list[j][1];
					gc = gcd(a,b);
					a /= gc;
					b /= gc;
					cout << a << "/" << b << endl;
				}
//				cout << endl << i << " : " << list[i][0] << "/" << list[i][1];
				last = i + 2;
				++i;
 			}
			++i;
			--n;
		}
//		cout << endl << last << " " << i;
//		for(j = 0; j <= i; ++j)
//			cout << list[j][0] << "/" << list[j][1]<< endl;
		cout << endl;
		--t;
	}
	return 0;
}
