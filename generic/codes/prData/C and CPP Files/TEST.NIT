#include<stdio.h>
main()
 {
  int a,b,c;
  clrscr();
  printf("\nenter two no.");
  scanf("%d%d",&a,&b);
  printf("\n\ta=%d\n\tb=%d",a,b);
  c=a+b;
  printf("\nsum=%d",c);
  getch();
}