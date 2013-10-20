#include<stdio.h>
#define NU 3;
#define NI 63;
#define NJ 100;
struct bit_wise
 {
  unsigned n : 2;
  unsigned n1 : 6;
  unsigned n2 : 8;
 }var;
main()
 {
  clrscr();
  printf("\nEnter any number");
  var.n=NU;
  var.n1=NI;
  var.n2=NJ;
  printf("\n%d",var.n);
  printf("\n%d",var.n1);
  printf("\n%d",var.n2);
  getch();
 }