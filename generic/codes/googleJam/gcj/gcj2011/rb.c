#include <stdio.h>
#include <math.h>

int main(){
    int t,n, p, tt, lt, currO, currB, curr, i;
    char r, lr;
    scanf("%d",&t);
	i = 1;
    while(t){
        scanf("%d",&n);

	lr = tt = lt = 0;
	currO = currB = 1;

        while(n){
	    scanf("%c", &r);
            scanf("%c", &r);
	    scanf("%d", &p);
		//printf("\n >> %c %d >>", r, p);
	    if('O' == r){ 
		curr = currO;
		currO = p;
	    }
	    else{
		curr = currB;
		currB = p;
	    }


	    p = abs(p - curr);
            if(lr != r){
		if(lt >= p){
	            	tt += 1;
			lt = 1;
		}
		else{
			tt += p + 1 - lt;
			lt = p + 1 - lt; 
		}
            }
            else{
		tt += p + 1;
		lt += p + 1;
            }

	    lr = r;
            --n;
//printf(">> %d >> ", p); 		printf("%d %d %d", tt, lt, curr); 		printf(">>>>>>> lt = %d\n", lt);
        }
	printf("Case #%d: %d", i++, tt);
        --t;
        if(t)
            printf("\n");
    }
}
