/**
logic used: just move forward keeping all those being in range with the given no...
**/
#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include	<vector>

using std::vector;

#include	<algorithm>

using std::sort;

int main(){
	int D, n, i, td , count , j , flag;
	vector <int> troops;

	while(true){
		cin >> D >> n;
		if((D == -1) && (n == -1))
			break;
		count  = 0;
		troops.clear();
		for(i = 0; i < n; ++i){
			cin >> td;
			troops.push_back(td);
		}
		sort(troops.begin(), troops.end());
		flag = 0;
		for(i = 0; i < n - 1; ){
				j = 1;
				while( ((i + j) < n - 1) && (troops.at(i) + D) >= (troops.at(i + j))){
					++j;
				}
				if(troops.at(i + j) > (troops.at(i + j - 1) + D)){
					flag = 0;
					++count;
					i += j;
				} else {
					flag = 1;
					++count;
					i += j + 1;

				}
		}
		if(flag == 0)
			++count;
		cout << count << endl;
	}
	return 0;
}
