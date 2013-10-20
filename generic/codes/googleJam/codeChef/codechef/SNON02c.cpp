/*
Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
*/

#include	<stdio.h>
#include	<math.h>
#include	<string.h>

using namespace std;

int main(){
	int t, n, gcd, i, temp, a, b, tn, k, carr;
	bool isprime;
	int tsum[40], gcda[7];
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		isprime = true;
                for(i = 2; i <= sqrt(n); ++i){
			if( n%i == 0){
				isprime = false;
				break;
			}
		}
		memset(tsum, 0, sizeof(tsum));
		k = 0;
		if(n == 2){
			tsum[k++] = 2;
		}
		else{
			if(isprime){
				carr = 1;
				tn = n;
				if((n % 2) == 0)
					n /= 2;
				else
					tn = (n - 1)/2;
				do{
					temp = n * (tn % 10);
					temp += carr;
					tsum[k++] = temp % 10;
					carr = temp / 10;
				}while(tn /= 10);
				while(carr > 0){
					tsum[k++] = carr % 10;
					carr /= 10;
				}
			}
			else{
				carr = 2;
				for(i = 2; i < n; ++i){
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
					gcd = i / gcd;
					carr += gcd;
					for(int j = 0; j < k; ++j){
						carr += tsum[j];
						tsum[j] = carr % 10;
						carr /= 10;
					}
					while(carr > 0){
						tsum[k++] = carr % 10;
						carr /= 10;
					}
					carr = 0;
				}
			}
		}
		carr = 0;
		for(i = 0; i < k; ++i){
			carr += (tsum[i] * n);
			tsum[i] = carr % 10;
			carr /= 10;
		}
		if(carr > 0){
			printf("%d", carr);
		}
		for(i = k - 1; i >= 0; --i)
			printf("%d",tsum[i]);
		printf("\n");
		--t;
	}
	return 0;
}
