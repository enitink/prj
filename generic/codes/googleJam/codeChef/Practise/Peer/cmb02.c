#include <stdio.h>

int Rev(int data){
	int temp = data;
	int revr = 0;
	while(temp){
		revr = revr * 10 +(temp % 10);
		temp = temp / 10;
	}
	return revr;
}

int main(){
	int t, k;
	scanf("%d", &t);
	while(t){
		scanf("%d",&k);
		++k;
		while(1){
			if(k == Rev(k))
				break;
			else 
				++k;			
		}
		printf("%d\n", k);
		--t;
	}
}
