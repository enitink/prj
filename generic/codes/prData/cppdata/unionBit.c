#include<stdio.h>
struct bit_wise
 {
  unsigned n : 2;
  unsigned n1 : 6;
  unsigned n2 : 8;
 }var;
struct bit_wise
  {
   unsigned i : 2;
  }z;
union number
 {
  int n;
  int n1;
  int n2;
 }x,y;
main()
{
  int c;
  clrscr();
  printf("\nPROGRAM FOR CHECKING UNIONS");
  printf("\nEnter any no.");
  scanf("%d",&x.n);
  printf("\nThe original x nos. are \n\t x.n=%d \n\t x.n1=%d \n\t x.n2 =%d",x.n,x.n1,x.n2);
  y=x;
  printf("\nThe original y nos. are \n\t y.n=%d \n\t y.n1=%d \n\t y.n2 =%d",y.n,y.n1,y.n2);
  c=x.n%10;
  z.i=c;
  printf("\nThe original z no. ia \n\t z.i=%d \n\t and c = %d ",z.i,c);
  getch();
}
