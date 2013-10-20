#include<stdio.h>
#include<math.h>
typedef struct
 {
  float r;
  float i;
 }roots;
main()
 {
  float a,b,c,d,t;
  roots x1,x2;
  clrscr();
  printf("\n\t\tPROGRAM FOR FINDING ROOTS OF A QUADRATIC EQUATION");
  printf("\n\n\t\t\t a*x^2+b*x+c=0");
  printf("\n\n\tENTER THE VALUE OF a,b & c");
  scanf("%f\n%f\n%f",&a,&b,&c);
 if(a==0)
    printf("\nTHE GIVEN EQUATION IS A LINEAR EQUATION");
 else
  {
    d=b*b-4*a*c;
     if(d==0)
       {
	x1.r=(-b)/(2*a);
	x2.r=x1.r;
	x1.i=x2.i=0;
       }
     else
     {
       if(d>0)
	 {
	  x1.r=-(b+d)/(2*a);
	  x2.r=(-b+d)/(2*a);
          x1.i=x2.i=0;
	 }
       else
	 {
	  t=abs(d);
	  x2.r=-b/(2*a);
	  x1.r=x2.r;
	  x1.i=sqrt(t)/(2*a);
	  x2.i=x1.i;
	  }

     }
   printf("\n\n\t\ta=%f\n\t\tb=%f\n\t\tc=%f",a,b,c);
   printf("\n\t\tDICRIMINANT=%f",d);
   printf("\n\n\tTHE ROOTS OF THE GIVEN EQUATIONS ARE");
   printf("\n\n\t\tFIRST ROOT=%f+%fi",x1.r,x1.i);
   printf("\n\t\tSECOND ROOT=%f-%fi",x2.r,x2.i);
  }
  getch();
}