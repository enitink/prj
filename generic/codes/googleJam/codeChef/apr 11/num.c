#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int t,s, flag, i;
	scanf("%d", &t);
	while(t){
		flag = 0;
		scanf("%d", &s);

		if(s == 2)
			flag = 1;
		else
			if(s > 1){
				flag = 1;
				--s;
				for(i = 2; i <= sqrt(s); ++i)
					if(!(s % 2)){
						flag = 0;
						break;
					}
			}
		printf("%s\n", (flag)? "BOB" : "ALICE");
		--t;
	}
	return 0;
}
