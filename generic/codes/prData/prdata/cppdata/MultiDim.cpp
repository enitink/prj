#include<iostream>

using std::cout;
using std::endl;

int main(){
	int a[2][2][2];
	int i, j, k;
	for(i = 1; i <= 2; ++i)
		for(j = 1; j <= 2; ++j)
			for(k = 1; k <= 2; ++k)
				a[i-1][j-1][k-1] = (i * 100) + (j * 10) + k;
	for(i = 0; i < 2; ++i){
		cout << endl << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
		for(j = 0; j < 2; ++j){
			for(k = 0; k < 2; ++k){
				cout << "  " << &a[i][j][k];
			}
			cout << endl;
		}
	}
	return 0;
}
