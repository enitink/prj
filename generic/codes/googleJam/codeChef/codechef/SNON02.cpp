/*
Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
*/

#include	<iostream>
#include	<cmath>
#include	<iomanip>

using namespace std;

int main(){
	int t, n, gcd, i, temp, a, b;
	bool isprime;
	double lcmsum, tsum;
	cin >> t;
	while(t){
		cin >> n;
		isprime = true;
                for(i = 2; i <= sqrt(n); ++i){
			if( n%i == 0){
				isprime = false;
				break;
			}
		}
		if(isprime)
			tsum = ((n * (n - 1) / 2) + 1);
		else{
			tsum = 2;
			for(i = 2; i < n; ++i){
				/*if((n % i) == 0)
					++tsum;
				else{*/
					gcd = 1;
					a = i;
					b = n;
					while(true){
						if( b == 0 ){
                            				gcd = a;
                            				break;
						}
                        			else{
                            				temp = a;
                            				a = b;
                            				b = temp % b;
						}
					}
					tsum += (i / gcd);
				//}
			}		
		}
		lcmsum = tsum * n;				
		cout << fixed << setprecision(0) << lcmsum << " " << tsum << endl;
		--t;
	}
	return 0;
}
