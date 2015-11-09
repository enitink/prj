#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
#include <iterator>
//#include <iostream>
using namespace std;

int main(){
	int t, n , k, a, flag, count, tn, v, odd, ch, i, j, st, pt, flag1, flag2;
	scanf("%d",&t);

	int data[50000];
	int dataS[2][50000];
	int dataR0[50000];
	list <int> dataR1[50000];
	list <int>::iterator it;

	while(t){
		memset(dataS, 0, sizeof(dataS));
		memset(dataR0, 0, sizeof(dataR0));
		for(i = 0; i < 50000; ++i)
			dataR1[i].clear();
		scanf("%d %d", &n, &k);
		flag = 0;
		tn = n;
		v = n / k;
		for(i = 0; i < n; ++i)
			scanf("%d", &data[i]);

		sort(&data[0], &data[n]);

		dataS[0][0] = data[0];
		++dataS[1][0];

		for(i = 1, j = 0; i < n; ++i){
			if(data[i] == dataS[0][j])
				++dataS[1][j];
			else{
				++dataR0[dataS[1][j]];
				dataR1[dataS[1][j]].push_back(j);
				++j;
				dataS[0][j] = data[i];
				++dataS[1][j];
			}
			if(dataS[1][j] > v){
				flag = 1;
				break;
			}
		}
		if(1 == flag)
			printf("-1");
		else{
			++dataR0[dataS[1][j]];
			dataR1[dataS[1][j]].push_back(j);
			//for(i = 0; i <=j; ++i){
			//	++dataR0[dataS[1][i]];
			//	dataR1[dataS[1][i]].push_back(i);
			//}
/*for(i = 0; i < 10; ++i){
	printf("\n dR0 : %d : ", dataR0[i]);
	for(it = dataR1[i].begin(); it != dataR1[i].end(); ++it)
        {
                cout << *it << " ";
        }
	printf("\n");
}*/
			st = 0;
			while(tn){
				odd = dataR0[v];
				ch = 0;
				count = 0;
				flag2 = flag1 = flag = 1;
				for (i = st ; i <= j && count < k; i++){
					if(!dataS[1][i])
						continue;
					if((dataS[1][i] != v) && (ch + odd < k)){
						++ch;
			    			printf("%d ", dataS[0][i]);
					}
					else{
						if(dataS[1][i] != v){
							flag = 0;
							i = dataR1[v].front();
							//dataR1[v].pop_front();
//printf("\n i = %d \n", i);
							//continue;
						}
							
						++ch;
						--odd;
						printf("%d ", dataS[0][i]);
					}
					--dataR0[dataS[1][i]];
					dataR1[dataS[1][i]].pop_front();
					--dataS[1][i];
//printf("\n dataS[ = %d ", dataS[1][i]);
					if( (flag1 == 0 && !dataR1[v-1].size()) || (flag1)){
						it = lower_bound(dataR1[dataS[1][i]].begin(), dataR1[dataS[1][i]].end(), i);
						dataR1[dataS[1][i]].insert(it, i);
					}
					else{
						flag2 = 0;
					}

					flag *= ((dataS[1][i])? 0 : 1);
					++dataR0[dataS[1][i]];
					++count;
					--tn;
					if(1 == flag)
						st = i + 1;
				}
				if(!flag2){
					dataR1[dataS[1][i]] = dataR1[dataS[1][i + 1]];
				}
				--v;
			}
		}
		printf("\n");
		--t;
	}
	return 0;
}
