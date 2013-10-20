#include<stdio.h>
main()
 {
  int j,i,k,l;
   clrscr();
 for(k=0;k<7;++k)
  {j=65;
  printf("\n\n\n\n");
   for(i=0;i<7-k;++i)
    {
     printf("    %c",j);
     ++j;
    }
   j=j-2;
   l=2*k;
   for(i=1;i<l;++i)
      printf("     ");

    l=6;
    if(k>=1)
     {
      j=j+1;
      l=7;
     }
   for(i=0;i<l-k;++i)
    {
      printf("    %c",j);
      --j;
    }
  }
   getch();
 }