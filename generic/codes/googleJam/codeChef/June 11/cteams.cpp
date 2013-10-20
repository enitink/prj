#include <cstdio>
#include <cmath>

using namespace std;

#define SIZE 50000

int arrAY[SIZE], LY = 0;
int arrAO[SIZE], HO = SIZE;
int arrRY[SIZE];
int arrRO[SIZE];

int main(){
    	int n, i, a, r, sumY = 0, sumO = 0, lc, j, flag;
	int *it;

    	scanf("%d", &n);
    	scanf("%d %d", &arrAY[LY], &arrRY[LY]);
    	sumY = arrRY[LY];

    	for(i = 1; i <= n; ++i){
		j = sumY - sumO;
		j = (j < 0)? j * (-1) : j;
        	printf("%d\n", j);
        	scanf("%d %d", &a, &r);
	        if(!(i % 2)){
        	    if(arrAY[LY] < a){           
        	        sumO += r;
        	        sumO -= arrRO[HO];
        	        sumY += arrRO[HO];
			arrAY[++LY] = arrAO[HO];
			arrRY[LY] = arrRO[HO--];
			flag = 2;
        	    }
        	    else{
        	        sumY += r;
			flag = 1;
        	    }
        	}
        	else{
        	    if(arrAY[LY] < a){           
        	        sumO += r;
			flag = 2;
        	    }
        	    else{
        	        sumY -= arrRY[LY];
        	        sumY += r;
        	        sumO += arrRY[LY];
			arrAO[--HO] = arrAY[LY];
			arrRO[HO] = arrRY[LY--];
			flag = 1;
        	    }   
        	}
		switch(flag){
		case 1:
		{
			it = lower_bound (arrAY, arrAY + LY + 1, a);
			lc = (int)(it - arrAY);
			if(lc 
		}
		break;
		case 2:
		{
			it = lower_bound (arrAO + HO, arrAO[SIZE], a);
			lc = (int)(it - arrA);
		}
		break;
		}
		printf("\n sumO = %d sumY = %d\n", sumO, sumY);
	}
    	return 0;
}

