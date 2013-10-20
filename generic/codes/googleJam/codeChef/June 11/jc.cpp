#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
#define SIZE 100000
 
int arrA[SIZE];
int arrR[SIZE];
 
int main(){
int n, i, a, r, sumY = 0, sumO = 0, lc, j;
int *it;
 
scanf("%d", &n);
scanf("%d %d", &arrA[0], &arrR[0]);
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
it = lower_bound (arrA, arrA + i, a);
lc = (int)(it - arrA);
if(lc >= i){
arrA[lc] = a;
arrR[lc] = r;
}
else{
//memmove(arrA + lc + 1, arrA + lc, i - lc);
//memmove(arrR + lc + 1, arrR + lc, i - lc);
arrA[lc] = a;
arrR[lc] = r;
}
}
return 0;
}
