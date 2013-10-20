/*Such "gradual" sequences are similar to the well-known Gray codes. Here is one way (of many) to generate the Gray code x[0], x[1], ..., x[2^n-1] starting with x[0] = 0. To get the value of x[i], if i is odd then x[i] is simply x[i-1] with the least significant bit flipped. Otherwise, let j be such that the j'th bit of x[i-1] is 1 and all bits of x[i-1] that are less significant than the j'th bit are 0. Then x[i] is obtained from x[i-1] by flipping the bit at position j+1. This can be done with clever bitwise operations.
Now, if a and b differ in more than one bit then we may simply output the Gray code. Otherwise, if a and b differ in only one bit then there is no solution for n = 1 or n = 2. Finally, I claim that there is always a solution for n >= 3 if a and b differ in precisely one bit.
We begin by finding a gradual sequence where 0 is not consecutive to a XOR b (XOR means bitwise XOR of binary numbers). To do this, start with the Gray code as mentioned above (or any other gradual sequence you can generate). If 0 and a XOR b are not consecutive, then we are done. Otherwise, since n >= 3 there is some bit 0 <= k < n such that 2^k is not consecutive to 0 in the gradual sequence. Now, let c[i] be the bit that changes between x[i] and x[i+1] and note that the x[i] can be recovered from the sequence of c[i] if we assume x[0] = 0. Let 2^j = a XOR b. Modify the sequence c[i] by changing c[i] = k values to c[i] = j and c[i] = j values to c[i] = k. This will generate a new gradual sequence y[i] that starts with y[i] = 0. However, by construction we will not have 0 and a XOR b adjacent in y[i]. Finally, the gradual sequence of values y[i] XOR a will not have a and b consecutive.
*/


#include <cstdio>
 
int gray[1<<15];
 
int main(){
	int T, N, A, B;
	for(int sh=1; sh<1<<15; sh<<=1)
		for(int i=0; i<sh; i++)
			gray[i+sh]=gray[sh-i-1]|sh;
	for(scanf("%d", &T); T--; ){
		scanf("%d %d %d", &N, &A, &B);
		if(N==1 || (N==2 && (A^B)!=3)){
			puts("-1");
			continue;
		}
		int rot=(__builtin_ffs(A^B)-2+N)%N;
		for(int i=0; i<1<<N; i++){
			printf("%d ", (((gray[i]<<rot)&((1<<N)-1))|(gray[i]>>(N-rot)))^A);
		}
		putchar('\n');
	}
	return 0;
}
