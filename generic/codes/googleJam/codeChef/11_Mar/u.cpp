#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;

int main(){
	int t, n , k, a, flag, v, i, d;
	scanf("%d",&t);

	int data[50000];
	list <int> dataS0;
	list <int> dataS1;
	list <int>::iterator it0, it1;

	while(t){
		dataS0.clear();
		dataS1.clear();

		scanf("%d %d", &n, &k);
		flag = 0;
		v = n / k;
		for(i = 0; i < n; ++i)
			scanf("%d", &data[i]);

		sort(&data[0], &data[n]);

		dataS0.push_back(data[0]);
		dataS1.push_back(1);

		for(i = 1; i < n; ++i){
			if(data[i] == dataS0.back()){
				d = dataS1.back();
				dataS1.pop_back();
				dataS1.push_back(d + 1);
			}
			else{
				dataS0.push_back(data[i]);
				dataS1.push_back(1);
			}
			if(dataS1.back() > v){
				flag = 1;
				break;
			}
		}
		
		for(it0 = dataS0.begin(), it1 = dataS1.begin(); it0 != dataS0.end(); ++it0, ++it1)
			printf("\n d0 %d : d1 %d", *it0, *it1); 
		
		/*if(1 == flag)
			printf("-1");
		else{
			while(n){
				for(it0 = dataS0.begin(), it1 = dataS1.begin(); it0 != dataS0.end(); ++it0, ++it1){
					--n;
				}
				--v;
			}
		}*/
		printf("\n");
		--t;
	}
	return 0;
}
