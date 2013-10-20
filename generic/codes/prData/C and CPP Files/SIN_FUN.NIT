/******************* PROGRAM FOR CALCULATING VALUE SIN()******************
********************            DATE-5/04/04            ******************
********************          BY:- NITIN KUMAR          ******************/

#include<stdio.h>
nsin(int *a,float *b,float *c,float *d,int *e);

main()
{
  int k,n=0;
  float x,r,s=0,t=1;
  clrscr();
  /***********************************************************************/
  printf("\n\t\t\tPROGRAM FOR CALCULATING VALUE OF SIN(x)");
  printf("\n\n\t\tENTER THE VALUE OF X ");
  scanf("%f",&x);
  printf("\n\n\t\tENTER THE VALUE OF K(1,2,3... )");
  scanf("%d",&k);
  r=(3.142*x)/180;
  if(k>1)
  nsin(&k,&r,&s,&t,&n);
  printf("\n\n\t\tVALUE OF SIN(%f)=%f",x,s);
  getch();
 }
  /**********************************************************************/
nsin(int *k,float *r,float *s,float *t,int *n)
 {
   int d;
   ++*(n);
   *t*=(*r)/(*n);
   d=*n%2;
   if(d!=0)
    {
     *s+=*t;
     *t=-*t;
    }
   if(*n>=*k-1)
     return;
   nsin(k,r,s,t,n);
   s=s;
   k=k;
 }
 /*************************************************************************/
