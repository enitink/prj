#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<cstring>

int main(){
	int noofcases, noofdata;
	cin >> noofcases;
	int * data = new int[100000];
	int * tempdata = new int[100000];
	int currmin, lastmin, flag, moves = 0;
	int i, j, k, l, ls, tls;
	int resultcount;
	for(i = 0; i < noofcases; ++i){
		resultcount = 0;
		cin >> noofdata;
		for(j = 0; j < noofdata; ++j){
			cin >> data[j];
		}
		flag = 0;
		ls = 0;
		while(!flag){
			flag = 1;
			currmin = ls;
			lastmin = ls;
			for(j = ls; j < noofdata; ++j){
				if(data[currmin] > data[j]){
					flag = 0;
					lastmin = currmin;
					currmin = j;
				}
			}
			j = currmin + 1;
			k = 1;
			tempdata[0] = data[currmin];
			for(	; j < noofdata; ++j){
				tls = j;
				if(data[j] < data[lastmin]){
					while(data[j] < data[tls - 1]){
						lastmin = j;
						--k;
						--tls;
					}
					tempdata[k] = data[j];
					++k;
				}
			}
			for(j = 0, l = 0; j < noofdata; ++j){
				if(data[j] > tempdata[k - 1]){
					tempdata[k + l] = data[j];
					++l;
				}
			}
			if(memcmp(data + ls, tempdata, sizeof(int) * (noofdata - ls)) != 0)
				++resultcount;
			memcpy(data + ls, tempdata, sizeof(int) * noofdata);			
			if((k == 1) && (tempdata[0] = data[ls]))
				flag = 0;
			if(ls == noofdata)
				break;
			ls += k;
		}
		cout << resultcount << endl;
	}	
	return 0;
}
