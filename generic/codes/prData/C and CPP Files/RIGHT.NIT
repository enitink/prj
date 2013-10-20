#include<stdio.h>
main()
{
 int n,d=0,r,j=0;
 clrscr();
 printf("\nProgram for finding sum of the digits of a number");
 printf("\nEnter any no.:");
 scanf("%d",&n);
 while(n!=0)
  {
   r=n%10;
   d=d+r;
   n=n/10;
   ++j;
  }
  printf("The sum of digits = %d ",d);
 getch();
}
