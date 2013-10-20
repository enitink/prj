/******************* PROGRAM FOR CALCULATING VALUE SINX********************
******************** DATE-16/10/03              ***************************
******************** BY:-NITIN KUMAR              *************************/

#include<stdio.h>
main()
{
  int k,n;
  float x,t=1,s=0,d,r;

  clrscr();
  /***********************************************************************/
  printf("\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SINX");
  printf("\n\n\t\tENTER THE VALUE OF X IN DEGREES ");
  scanf("%f",&x);
  printf("\n\n\t\tENTER THE VALUE OF K(1,2,3... )");
  scanf("%d",&k);

  r=x*3.14/180;
  /**********************************************************************/

  for(n=1;n<=k;++n)
   {
     t*=r/n;
     d=n%2;

     if(d!=0)
      {
	s+=t;
	t=-t;
      }
    }
  /***********************************************************************/
  printf("\n\n\t\tVALUE OF SIN%f=%f",x,s);
  getch();
 }