#include	<iostream>

using std::cout;
using std::endl;
using std::cin;

int data;

int Rev(){
	int temp = data;
	int revr = 0;
	while(temp){
		revr = revr * 10 +(temp % 10);
		temp = temp / 10;
	}
	return revr;
}

int main(){
	int cases, count , r;
	cin >> cases;
	
	while(cases){
		cin >> data;
		count = 0;
		while(data != (r = Rev())){
			++count;
			data = r + data;
		}
		cout << count << " " << data << endl;
		--cases;
	}
	return 0;
}
