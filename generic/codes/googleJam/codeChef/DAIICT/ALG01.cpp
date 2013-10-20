#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	int t, n, d, tn, m;
	int res1[10001];
	int res2[10001];
	scanf("%d", &t);
	while(t){
		memset(res1, 0, sizeof(res1));
		memset(res2, 0, sizeof(res2));
		scanf("%d", &n);
		tn = n;
		while(tn){
			scanf("%d", &d);
			res1[d] = 1 + *(max_element(res1, res1 + d));
			res2[d] = 1 + *(max_element(res2 + d + 1, res2 + n + 1));
			//printf("\n %d %d %d %d", n , d, res1[d], res2[d]);
			--tn;
		}
		d = ((m = *max_element(res1, res1 + n + 1)) > (tn = *max_element(res2, res2 + n))? m : tn);
		printf("%d", d);
		--t;
		if(t)
			printf("\n");
	}
}
