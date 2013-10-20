#include<stdio.h>
main()
 {
  int i=0,p1=42;
  char p[10];
  clrscr();
  printf("\nenter the password");
  while(p[i]!='\0')
   {
     p[i]=getch();
     printf("%c",p1);
     ++i;
   }
  if((p[0]=='n')&&(p[1]=='i')&&(p[2]=='t')&&(p[3]=='i')&&(p[4]=='n'))
    printf("\nu have got the right password");
  else
   printf("\nu haven't got the password right");
  getch();
 }
