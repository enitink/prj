#include	<iostream>

using std::cin;
using std::cout;
using std::endl;

#include	<cstring>

int main(){
	int noofcases, noofdata;
	cin >> noofcases;
	int * data = new int[1000000];
	int * tempdata = new int[1000000];
	int i,j,k,l = 0,tk, flag;
	int min;
	long int count;

	for(i = 0; i < noofcases; ++i){
		cin >> noofdata;
		count = 0;
		for(j = 0; j < noofdata; ++j){
			cin >> data[j];
		}
		l = 0;
		flag = 0;
		while(!flag){
			tempdata[0] = 10000001;
			flag = 1;
			for(j = l, k = 0; j < noofdata; ++j){
				while(tempdata[k] > data[j]){
					min = tempdata[k];
					--k;
					if(k < 0)
						break;
				}
				if(data[j] < min){
					++k;
					tempdata[k] = data[j];
				}
			}
			tk = k;
			for(j = 0; j <= noofdata; ++j){
				if(data[j] > tempdata[tk]){
					++k;
					tempdata[k] = data[j];
				}
			}
			if(memcmp(data + l, tempdata, sizeof(int) * (noofdata - l)) != 0){
					++count;
					flag = 0;
			}
			memcpy(data + l, tempdata, sizeof(int) * noofdata);
			l += tk;
		}
		cout << count << endl;
	}	
	return 0;
}
