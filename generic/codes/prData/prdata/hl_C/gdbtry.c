#include <stdio.h>

int auth(int t){
	if(t)
		return 1;
	else
		return 0;
}

int main(){
	printf("%d", auth(3));
	return 0;
}
