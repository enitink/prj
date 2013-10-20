#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int t, n, res;
	string nm;
	char vt;
	map <string, int> dataMap;
	map <string, int>::iterator it;
	int votes[100];
	cin >> t;
	while(t){
		cin >> n;
		dataMap.clear();
		memset(votes, 0, sizeof(votes));
		while(n){
			cin >> nm >> vt;
			//cout << endl << nm << " : " << vt;
			dataMap[nm] = (vt == '+')? 1 : -1;
			--n;
		}
		res = 0;
		for (it=dataMap.begin() ; it != dataMap.end(); it++ )
		    res += (*it).second;
		cout << res;
		--t;
		if(t)
			cout << endl;
	}
	return 0;
}
