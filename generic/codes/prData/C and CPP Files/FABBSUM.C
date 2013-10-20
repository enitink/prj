#include<stdio.h>
#include<conio.h>

void main()
{
   double f1=0,f2=1,f=0;
   double sum=0;
   double avg;
   int i;

   //clrscr();

   for(i = 0; i < 99 ; ++i)
   {
	printf("  %lf ",f);
        f=f1+f2;
	sum=sum+f;
	f2=f1;
	f1=f;
   }

   avg = (float) (sum/99.0);

   printf("\n\t Sum = %lf \n\t Avg = %ff",sum,avg);

   getch();
}