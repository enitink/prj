#include<stdio.h>
interchange(int *a,int *b);
main()
 { int a,b;
   clrscr();
   printf("\nENTER ANY TWO NUMBERS:-");
   scanf("%d%d",&a,&b);
   printf("\n   A=%d\n   B=%d",a,b);
   interchange(&a,&b);
   printf("\n   A=%d\n   B=%d",a,b);
   getch();
 }

interchange(int *b,int *a)
 {
   *a+=*b;
   *b=*a-*b;
   *a=*a-*b;
   return;
 }
