#include<stdio.h>
main()
{
 char string[20];
 int i=0,j;
 clrscr();
 printf("ENTER THE STRING : ");
 fflush(stdin);
 gets(string);
 printf("\nTHE ORGINAL STRING IS %s",string);
 while(string[i]!='\0')
  {
   if(string[i] >=97 && string[i] <=122)
     string[i]=string[i]-32;
   ++i;
  }
 printf("\nTHE CONVERTED STRING IS\n ");
 for(j=0;j<i;++j)
   printf("%c",string[j]);
 getch();
}