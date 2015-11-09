#include <stdio.h>

int main(){
	int t, r;
	char c;
	int arr[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	scanf("%d", &t);
	scanf("%c", &c);
	while(t){
		r = 0;
		scanf("%c", &c);
		while(('\n' != c) && ('\0' != c)){
			//printf("%d ", c - 65);
			r += arr[c - 65];
			scanf("%c", &c);
		}
		printf("%d",r);
		--t;
		if(t)
			printf("\n");
	}
}
