#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    	int n, i, a, r, sumY = 0, sumO = 0, lc, j;

	vector <int> arrA;
	vector <int> arrR;
	vector <int>::iterator it;

    	scanf("%d", &n);
    	scanf("%d %d", &a, &r);
	arrA.push_back(a);
	arrR.push_back(r);

    	sumY = arrR[0];

    	for(i = 1; i <= n; ++i){
        	printf("%d\n", abs(sumY - sumO));
        	scanf("%d %d", &a, &r);

            	lc = i / 2;

	        if(!(i % 2)){
        	    if(arrA[lc] < a){           
        	        sumO += r;
        	        sumO -= arrR[lc];
        	        sumY += arrR[lc];
        	    }
        	    else{
        	        sumY += r;
        	    }
        	}
        	else{
        	    if(arrA[lc] < a){           
        	        sumO += r;
        	    }
        	    else{
        	        sumY -= arrR[lc];
        	        sumY += r;
        	        sumO += arrR[lc];
        	    }   
        	}

		it = lower_bound (arrA.begin(), arrA.end(), a);
		lc = (int)(it - arrA.begin());
		if(lc >= i){
			arrA.push_back(a);
			arrR.push_back(r);
		}
		else{
			arrA.insert(it, a);
			arrR.insert(it, r);
		}
	}
    	return 0;
}

