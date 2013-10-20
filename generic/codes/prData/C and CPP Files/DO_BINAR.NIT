#include<stdio.h>
main()
{
 int n,r,x,i=0,j,a[10];
 clrscr();
 printf("\nenter any number to find its binary equivalent");
 scanf("%d",&n);
 x=n;
 do
   {
    r=n%2;
    a[i]=r;
    ++i;
    n=(n-r)/2;
   }
 while(n>0);
 printf("\nbinary code of %d is",x);
 for(j=i-1;j>=0;--j)
  {
   printf("%d",a[j]);
  }
getch();
}