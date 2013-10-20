#include<stdio.h>
main()
{
 int n,r,x,i=0,j,a[10];
 clrscr();
/* scanf("%d",&n);*/
for(n=2;n<1000;++n)
{ x=n;
  while(n>0)
   {
    r=n%2;
    a[i]=r;
    ++i;
    n=(n-r)/2;
   }

 printf("\nbinary code of %d is ",x);
 for(j=i;j>=0;--j)
  {
   printf("%d",a[j]);
   a[j]=0;
  }
 i=0;
 }
getch();
}