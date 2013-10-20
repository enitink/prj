/*PROGRAM TO COUNT NO. OF CHARECTERS & VOWELS IN THE GIVEN SENTENCE */
#include<stdio.h>
main()
 {
  char c;
  int s[40],l=0,sp=0,i=0;
  clrscr();
  printf("\nenter any string");
  while(1)
   {
    scanf("%c",&c);
    s[i]=c;
    ++i;
    ++l;
     if(c=='\n')
      break;
   }
   --l;
   for(i=0;i<l;++i)
   {
    c=s[i];
    if(c==' ')
      ++sp;
   }
  printf("\ntotal no. of alphabets=%d",l-sp);
  getch();
 }


