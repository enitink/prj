#include<stdio.h>
#include<math.h>
#include<dos.h>
float a,b,d;
result();
main()
{
  int c=0;
  while(c!=5)
  { clrscr();
    printf("\nPROROGRAM FOR DIFFERENT MATHEMATICAL OPERATIONS");
    printf("\n\t1.ADDITION.\n\t2.SUBSTRACTION.\n\t3.MULTIPLICATION.\n\t4.DIVISION.\n\t5.EXIT.");
    printf("\n\tENTER THE CHOICE NO.");
    scanf("%d",&c);
    switch(c)
     {
      case 1:
	 result();
	 goto add;
      case 2:
	 result();
	 goto sub;
      case 3:
	 result();
	 goto mul;
      case 4:
	 result();
	 goto div;
      default:
	 printf("\n\nTHANKU FOR USING THIS PROGRAM,\n\n\t\t\"PRESS ANY KEY TO GET OUT OF THIS\"");
	 getch();
	 exit(0);
     }
   }
add:
 {
    d=a+b;
    printf("\nTHE ADDITION OF THE TWO GIVEN NOS. %f & %f IS =%f",a,b,d);
    sleep(5);
    exit(0);
 }
sub:
 {
    d=a-b;
    d=abs(d);
    printf("\nTHE DIFFRENCE OF THE TWO GIVEN NOS. %f & %f IS =%f",a,b,d);
    sleep(5);
    exit(0);
 }
mul:
 {
    d=a*b;
    printf("\nTHE MULTIPLICATION OF THE TWO GIVEN NOS. %f & %f IS =%f",a,b,d);
    sleep(5);
    exit(0);
 }
div:
 {
    d=a/b;
    printf("\nTHE DIVISION OF THE TWO GIVEN NOS. %f & %f IS =%f",a,b,d);
    getch();
    exit(0);
 }
}
result()
 {
  printf("\nenter any two nos.");
  scanf("%f%f",&a,&b);
  return;
 }