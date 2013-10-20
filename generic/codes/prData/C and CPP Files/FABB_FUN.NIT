#include<stdio.h>
void fabb(int n);
main()
{
 int n;
 clrscr();
 printf("\n\tPROGRAM FOR GENERATING FABBONACCI SERIES UPTO GIVEN NOS. OF TERMS");
 printf("\n\nENTER THE NUMBER OF TERMS (n)");
 scanf("%d",&n);
 printf("\nTHE SERIES IS AS FOLLWOS:- ");
 fabb(n);
 getch();
}
void fabb(int n)
 {
  int i=0,f=0,f1=0,f2=1;
  for(;i<n;++i)
   {
    printf("%d ",f);
    f=f1+f2;
    f2=f1;
    f1=f;
   }
  return;
 }