/************ PROGRAM FOR CALCULATING VALUE SININVERSE(X)******************
******************** DATE-21/12/03              ***************************
******************** BY:-NITIN KUMAR              *************************/

#include<stdio.h>
main()
{
  int k,n,n1,s1;
  float x,t=1,s=0,d,r;

  clrscr();
  /***********************************************************************/
  printf("\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SININVERSE(X)");
  printf("\n\n\t\tENTER THE VALUE OF X(1 TO -1)");
  scanf("%f",&x);
  printf("\n\n\t\tENTER THE VALUE OF K(1,2,3... )");
  scanf("%d",&k);
  /***********************************************************************/
  for(n1=0;n1<=90;++n1)
   {
    s1=n1;
    r=n1*3.14/180;
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
     if(s==x)
      break;
    s=0;
   }
   --s1;
  /***********************************************************************/
  printf("\n\n\t\tVALUE OF SININVERSE%f=%f",x,s1);
  getch();
 }
