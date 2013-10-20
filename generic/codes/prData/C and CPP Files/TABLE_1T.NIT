#include<stdio.h>
main()
{
 int i,j,p;
 clrscr();
 printf("\n\t\t\t  THE TABLE OF 1 TO 10\n");
 printf("  -----------------------------------------------------------------------------");
 for(i=1;i<=10;++i)
  {
   printf("\n\tTABLE OF %3d IS:",i);
   for(j=1;j<=10;++j)
    printf("%4d",i*j);
   }
 printf("\n  -----------------------------------------------------------------------------");
  getch();
}
