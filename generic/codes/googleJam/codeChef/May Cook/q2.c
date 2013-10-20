#include <stdio.h>

int main(){
	int t, n , f;
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		if((n == 3) || (n == 2))
			f = 0;
		else{
			if((n - 1) & ((n-1) - 1))
				f = 0;
			else 
				f = 1;
		}
		if(f)
			printf("Bhima");
		else
			printf("Arjuna");
		--t;
		if(t)
			printf("\n");
	}
	return 0;
}
