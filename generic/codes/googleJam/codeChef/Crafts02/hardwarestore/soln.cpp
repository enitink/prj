//Logic used.. just generate all those possible no from the given set... then.. push all recieved into vector... then search the max element... :-)
#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<vector>
using std::vector;

#include	<algorithm>
#include	<numeric>
using std::max_element;

int main(){
	int T, N, D, No, i, j, tempno, count;
	vector <int> list;
	cin >> T;
	while(T){
		No = 0;
		cin >> N;
		list.clear();
		count = 0;
		for(i = 0; i < 3; ++i){		
			cin >> D;
			No = No * 10 + D;
		}
		for(i = 1; i <= 9; ++i)
			for(j = 0; j<=9; ++j){
				tempno = (i * 10000) + (No * 10) + j;
				//cout << tempno << endl;
				if((tempno % N) == 0){
					list.push_back(tempno);
					++count;
				}
			}
		if(list.empty())
			cout << 0 << endl;
		else{
			tempno = * max_element(list.begin(), list.end());
			cout << (tempno) / 10000 << " " << (tempno) % 10 << " " << (tempno) / N << endl;
		}
		--T;
	}
	return 0;
}
