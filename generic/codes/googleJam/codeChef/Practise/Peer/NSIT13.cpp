#include	<iostream>
#include	<cstring>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int t = 10, c, d, i, j, k;
	int a[10];
	bool flag;
	while(t){
		k = 0;
		memset(a, 0, sizeof(a));
		for(j = 0; j < 10; ++j){
			cin >> d;
			d %= 42;
			flag = false;
			for(i = 0; i < k; ++i)
				if(a[i] == d){
					flag = true;
					break;
				}
			if(flag == false){
				a[k++] = d;
			}		
		}
		cout << k << endl;
		--t;
	}
	return 0;
}
