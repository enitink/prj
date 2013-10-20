#include <stdio.h>

int arr[100010];
int v, i, j;

void ufunc(){
	int k;
	for(k = i; k <= j; ++k)
		arr[k] = v - arr[k];
}

int func(){
	int k;
	int res = -1;

	for(k = i; k < j && k <= 100000; ++k){
		if((arr[k] == arr[k + 1]) && ((3 == res) || (-1 == res)))
			res = 3;
		else
			if((arr[k] >= arr[k + 1]) && ((2 == res) || (-1 == res) || (3 == res)))
				res = 2;
			else
				if((arr[k] <= arr[k + 1]) && ((1 == res) || (-1 == res) || (3 == res)))
					res = 1;
				else{
					res = 0;
					break;
				}
	}
	return res;
}

int main(){
	int n, q, c;
	scanf("%d %d", &n, &q);
	
	for(c = 0; c < n; ++c)
		scanf("%d", &arr[c]);

	for(c = 0; c < q; ++c){
		scanf("%d %d %d", &v, &i, &j);
		if(0 == v)
			printf("%d\n",func());
		else
			ufunc();
	}
}
