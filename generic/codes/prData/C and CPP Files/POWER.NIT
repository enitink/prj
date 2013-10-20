#include<stdio.h>
#include<math.h>
float r1=1;
power(float a);
 main()
  {
    float a,b;
    int i;
    clrscr();
    printf("\nPROGRAM FOR THE CALCULATION OF X^Y");
    printf("\nenter the value of x");
    scanf("%f",&a);
    printf("\nenter the value of y");
    scanf("%f",&b);
   for(i=0;i<b;++i)
   {
    power(a);
    printf("\n %4f ** %4i = %4f",a,(i+1),r1);
   }
   /* printf("\nVALUE OF %f^%f=%f",a,b,r2);*/
    getch();
  }
   power(float a)
  {
   r1=r1*a;
   return;
  }