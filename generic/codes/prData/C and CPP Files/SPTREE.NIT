#include<stdio.h>
main()
{
 int i,j,n;
 clrscr();
 printf("enter the value of n");
 scanf("%d",&n);
 for(i=1;i<=n;++i)
  {
    printf("\n");
   for(j=n-i;j>0;--j)
    printf(" ");
   for(j=0;j<2*i-1;++j)
    printf("*");
  }
 for(i=n-1;i>=1;--i)
  {
    printf("\n");
   for(j=n-i;j>0;--j)
    printf(" ");
   for(j=0;j<2*i-1;++j)
    printf("*");
  }
 getch();
 }
