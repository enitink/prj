#include<stdio.h>
main()
 {
  int i,j,n;
  clrscr();
  printf("\nENTER THE NO. FOR WHICH U WANT TO GENERATE A SERIES");
  scanf("%d",&n);
   for(i=1;i<=n;++i)
    {
     printf("\n\n");
     for(j=1;j<=i;++j)
      printf("%4d",j);
    }
 getch();
 }
