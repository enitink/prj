#include	<stdio.h>
#include	<string.h>
#include	<algorithm>

using std::sort;

int itoa(int n, char s[]){
	int i = 0;
	do{
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);
	s[i] = '\0';
	return i;
}
int main(){
	int t, d, dd, l;
	char sd[11], rd[11];
	scanf("%d",&t);
	while(t){
		scanf("%d %d",&d, &dd);
		l = itoa(d, sd);
		itoa(dd, rd);
		sort(sd, sd + l);
		sort(rd, rd + l);
		if(strcmp(sd,rd) == 0)
			printf("1");
		else
			printf("0");
		printf("\n");
		--t;
	}
	return 0;
}
