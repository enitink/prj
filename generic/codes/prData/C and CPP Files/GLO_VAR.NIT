#include<stdio.h>
#include<math.h>
int a,b;
int add(int x,int y);
main()
{
  int c,d;
  clrscr();
  printf("\nPROGRAM FOR THE CALCULATING SUM & DIFF. OF TWO GIVEN NOS. USING GLOBAL VARIABLE");
  printf("\n\nENTER ANY TWO NOS.");
  scanf("%d%d",&c,&d);
  add(c,d);
  b=abs(b);
  printf("\nTHE SUM OF THE GIVEN NOS. IS %d",a);
  printf("\nTHE DIFFERENCE OF THE GIVEN NOS. IS %d",b);
  getch();
}
 int add(int c,int d)
  {
    a=c+d;
    b=c-d;
    return;
  }