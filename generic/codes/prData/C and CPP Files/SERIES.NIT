/******************* PROGRAM FOR CALCULATING VALUE SERIES******************
******************** DATE-5/04/04              ***************************
******************** BY:-NITIN KUMAR              *************************/

#include<stdio.h>
series(int k,int n,float x,float *s,float *t);
main()
{
  int k,n=1;
  float x,s=1,t=1;
  clrscr();
  /***********************************************************************/
  printf("\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SERIES");
  printf("\n\n\t\tENTER THE VALUE OF X ");
  scanf("%f",&x);
  printf("\n\n\t\tENTER THE VALUE OF K(1,2,3... )");
  scanf("%d",&k);
  if(k>2)
   series(k,n,x,&s,&t);
  if(k==2)
   ++s;
  printf("\n\n\t\tVALUE OF SERIES=%f",s);
  getch();
 }
  /**********************************************************************/
series(int k,int n,float x,float *s,float *t)
   {
     *s+=*t;
     *t=(*t)*(x/n);
     *t=-(*t);
     ++n;
     if((n>k))
      return;
     series(k,n,x,s,t);
   }
  /***********************************************************************/