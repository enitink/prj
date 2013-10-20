#include<stdio.h>
typedef struct
  {
    float r;
    int i;
  }complex;
float add_complex(float a,float b);
main()
 {
  complex a,b,c;
  clrscr();
  printf("\nprogram for the addition of two complex numbers a+ib");
  printf("\nenter the real part (a) of the complex no.");
  scanf("%f%f",&a.r,&b.r);
  printf("\nenter the imaginary part (b) of the complex no.");
  scanf("%d%d",&a.i,&b.i);
   printf("\n%d6f%d6f",&a.r,&b.r);
   printf("\n%d%d",&a.i,&b.i);
   c.r=add_complex(a.r,b.r);
   c.i=add_complex(a.i,b.i);
  printf("\nprintf the sum of the two complex no. is %d+i%d",c.r,c.i);
  getch();
 }
 float add_complex(float a,float b)
  {
   float c;
     c=a+b;
     return(c);
   }