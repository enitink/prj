//Octal Looks

#include	<stdio.h>

int main(){
	int t,d,c;
	scanf("%d",&t);
	while(t){
		scanf("%d", &d);
		c = 0;
		while(d > 0){
			if(d & 1)		
				++c;
			d >>= 1;
		}
		--t;
		if((c % 2) == 0)
			c = c * 5;
		else
			c = c * 5 - 1;
		printf("%d\n", c );
	}
	return 0;
}
