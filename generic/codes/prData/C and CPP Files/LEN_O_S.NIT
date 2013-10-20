/*PROGRAM TO FIND THE LENGTH OF A STRING USING FUNCTIOIN */
#include<stdio.h>
int length(char *s);
main()
 {
  int l=0;
  char s[40];
  clrscr();
  printf("\nenter any string");
  fflush(stdin);
  gets(s);
  l=length(s);
  printf("The length of the String is %d Characters %s",l,s);
  getch();
 }
int length(char *s)
 {
  int l=0;
  while(*s!='\0')
   {
    if(*s!=' ')
       ++l;
    ++s;
   }
   return(l);
 }

