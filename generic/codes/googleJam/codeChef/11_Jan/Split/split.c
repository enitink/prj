#include	<stdio.h>
#include	<string.h>

int main(){
	int k, n, t, d, c;
	int data[1000], dataCount[500], cuts[1000];//, temp[500];
	int jack[500], jill[500];
	int flag;

	scanf("%d", &k);
	while(k){
		scanf("%d", &n);
		t = n;
		memset(dataCount, 0, sizeof(dataCount));
		memset(data, 0, sizeof(data));
		while(n){
			--n;
			scanf("%d", &d);
			data[n] = d;
			++dataCount[d - 1];
		}
		//memset(temp, 0, sizeof(temp));
		memset(jack, 0, sizeof(jack));
		memset(jill, 0, sizeof(jill));
		memset(cuts, 0, sizeof(cuts));
		c = 0;
		n = t;
		flag = 1;
		while(t){
			--t;
			//printf("\nflag %d data[t] %d", flag, data[t]);
			if(flag){
				if(dataCount[data[t] - 1] / 2 == jack[data[t] - 1]){
					++jill[data[t] - 1];
					cuts[c++] = n - t - 1;
					flag = 0;
				}
				else{
						++jack[data[t] - 1];
				}
			}
			else{
				if(dataCount[data[t] - 1] / 2 == jill[data[t] - 1]){
					++jack[data[t] - 1];
					cuts[c++] = n - t - 1;
					flag = 1;
				}
				else{
						++jill[data[t] - 1];
				}
			}
		}
		printf("%d\n",c);
		d = 0;
		while(c){
			printf("%d",cuts[d++]);
			--c;
			if(c)
				printf(" ");
		}
		--k;
		if(k)
			printf("\n");
	}
	return 0;
}
