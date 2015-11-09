#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int t, n , k, a, flag, count, tn, v, odd, ch, i, j, st, pt;
	scanf("%d",&t);

	int data[50000];
	int dataS[2][50001];
	int dataR0[50000];
	int dataR1[50000];
	int dataR2[50000];

	while(t){
		memset(dataS, 0, sizeof(dataS));
		memset(dataR0, 0, sizeof(dataR0));
		for(i = 0; i < 50000; ++i)
			dataR2[i] = dataR1[i] = 50000;
		dataS[0][50000] = 1000000001;

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
			for(i = 0; i <=j; ++i){
				++dataR0[dataS[1][i]];
				//printf(">>> %d ", dataR1[dataS[1][i]]);
				dataR1[dataS[1][i]] = (dataS[0][dataR1[dataS[1][i]]] < dataS[0][i]) ? dataR1[dataS[1][i]] : i;
				dataR2[dataS[1][i]] = i;
			}
//			for(i = 0; i < 10; ++i)
//				printf("\n dR0 %d dR1 %d dR2 %d \n", dataR0[i], dataR1[i], dataR2[i]);
//			for(i = 0; i < 8; ++i)
//				printf("\n dR0 %d dR1 %d \n", dataR0[i], dataR1[i]);
			st = 0;
			while(tn){
				odd = dataR0[v];
				ch = 0;
				count = 0;
				flag = 1;
//				printf("\n v = %d\n", v);
				for ( i = st ; i <= j && count < k; i++){
					if(!dataS[1][i])
						continue;
					if((dataS[1][i] != v) && (ch + odd < k)){
						++ch;
			    			printf("%d ", dataS[0][i]);
					}
					else{
						if(dataS[1][i] != v){
							i = dataR1[v];
							//continue;
						}
							
						++ch;
						--odd;
						printf("%d ", dataS[0][i]);
					}
					pt = find(dataS[1] + i + 1 + st, dataS[1] + dataR2[dataS[1][i]], dataS[1][i]) - dataS[1];
					//printf("\npt = %d %d\n", pt, dataR2[dataS[1][i]]);
					if(pt > 0)
						dataR1[dataS[1][i]] = pt;
					else
						dataR1[dataS[1][i]] = 50000;

					--dataR0[dataS[1][i]];
					--dataS[1][i];
					flag *= ((dataS[1][i])? 0 : 1);
					++dataR0[dataS[1][i]];

					dataR1[dataS[1][i]] = 50000;
					pt = find(dataS[1] + st, dataS[1] + dataR2[dataS[1][i]], dataS[1][i]) - dataS[1];
					//printf("\npt = %d %d\n", pt, dataR2[dataS[1][i]]);
					if(pt < 50000)
						dataR1[dataS[1][i]] = pt;
					else
						dataR1[dataS[1][i]] = 50000;


					++count;
					--tn;
					if(1 == flag)
						st = i + 1;
				}
				--v;
			}
		}
		printf("\n");
		--t;
	}
	return 0;
}
