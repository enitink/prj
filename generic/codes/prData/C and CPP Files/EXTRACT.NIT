#include<stdio.h>
main()
{
 char string[20],extracted[10];
 int n,m,i,j=0;
 clrscr();
 printf("\n\tPROGRAM FOR EXTRACTING DESIRED NO. OF CHARACTERS FROM A STRING");
 printf("\n\nENTER THE STRING");
 gets(string);
 printf("\nENTER FROM WHERE TO START : ");
 scanf("%d",&n);
 printf("\nENTER NO. OF CHARACTER TO EXRACT : ");
 scanf("%d",&m);
 for(i=n-1;i<n+m;++i)
   {
     extracted[j]=string[i];
     ++j;
    }
 printf("\n\nTHE ORIGINAL STRING IS  : %s",string);
 printf("\nTHE EXTRACTED STRING IS : %s",extracted);
 getch();
}