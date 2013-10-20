//bouncy nos.
#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<cstring>

int arr[15];

bool isinc(int i){
	int j;
	for(j = 0; j < i - 1; ++j){
		if(arr[j] > arr[j + 1])
			return false;
	}
	return true;			
}

bool isdec(int i){
	int j;
	for(j = 0; j < i - 1; ++j)
		if(arr[j] < arr[j + 1])
			return false;
	return true;			
}

int main(){
	int t, i;
	char ch;
	cin >> t;
	cin.get();
	while(t){
		--t;
		i = 0;
		memset(arr, 0, sizeof(arr));
		while( (ch = cin.get()) != '\n'){
			arr[i++] = ch - '0';
		}
		if(isinc(i)){
			cout << "0" << endl;
			continue;
		}
		if(isdec(i)){
			cout << "0" << endl;
			continue;
		}
		cout << "1" << endl;
	}
	return 0;
}
