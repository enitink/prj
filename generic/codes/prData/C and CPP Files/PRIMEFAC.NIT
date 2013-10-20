#include<stdio.h>
pr_factor(int a);
int r[20];
static int j=0,k=1;
main()
{
 int i,n;
 clrscr();
 printf("\n\t\tPROGRAM FOR FINDING PRIME FACTORS OF A NUMBER\n");
 printf("\n******************************************************************************\n");
 printf("\n******************************************************************************");
 printf("\n* ENTER ANY NO.");
 scanf(" %d",&n);
 printf("\n******************************************************************************\n");
 r[0]=0;
 pr_factor(n);
 printf("\n******************************************************************************\n");
 printf("\n* THE PRIME FACTORS OF %d ARE:- ",n);
  for(i=0;i<j;++i)
  {
   printf(" %d ",r[i]);
  }
 printf("\n******************************************************************************\n");
 printf("* VALUE OF K=%d",k);
 printf("\n******************************************************************************\n");
 printf("*\t\t  THANK YOU FOR USING THIS PROGRAM");
 printf("\n******************************************************************************\n");
 getch();
}

pr_factor(int n)
 {
  int t,i=2,x;
  float ti;
  x=n;
  while(n>=r[0])
   {
     t=n/i;
     ti=1.0*n;
     ti=ti/i;
    if(t==ti)
     {
      r[j]=i;
      ++j;
      n=n/i;
      k=k*i;
      if(k==x)
	break;
     continue;
    }
    ++i;
   }
  return;
 }