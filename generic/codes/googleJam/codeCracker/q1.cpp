#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<vector>

using std::vector;

#include	<numeric>

using std::accumulate;

int main(){
	vector <int> data;
	int cases, datano, idata;
	int i,j, sum, tsum;
	cin >> cases;
	for(i = 0; i < cases; ++i){
		cin >> datano;
		data.clear();
		for(j = 0; j < datano; ++j){
			cin >> idata;
			data.push_back(idata);
		}
		sum = accumulate(data.begin(), data.end(), 0);
		tsum = 0;
		for(j = 0; j < datano && (sum - tsum)/2 > tsum; ++j){
			tsum += data.at(j);
		}
		cout << tsum << endl;
	}
	return 0;
}
