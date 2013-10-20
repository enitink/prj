#include<stdio.h>
void factorial(int n,long int  *f);
main()
{
 int x,n;
 long int f=1;
 clrscr();
 printf("\nENTER ANY NO. TO FIND IT'S FACTORIAL");
 scanf("%d",&n);
 x=n;
 factorial(x,&f);
 printf("\nTHE FACTORIAL OF %d IS EQUAL TO %ld",n,f);
 getch();
}

void factorial(int n,long int *f)
 {
  *f*=n;
  --n;
  if(n==0)
   return;
  factorial(n,f);
 }