#include	<stdio.h>
#include	<math.h>

int main(){
	int t, len;
	int sum;
	char ch;
	scanf("%d",&t);
	ch = getchar();
	while(t){
		sum = 0;
		len = 0;
		while((ch = getchar()) != '\n'){
			sum += ch;
			++len;
		}
		printf("%c\n", (int)((sum * 1.0)/len));
		--t;
	}

	return 0;
}
