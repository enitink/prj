#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
roman(int x,char c);
char re[20];
int g;
main()
{
 int n,r,x,j=0,i=0,a[10];
 char al[]="IVXLCDM";
 clrscr();
 textcolor(RED+LIGHTGRAY);
 cprintf("\n        PROGRAM FOR CONVERTING A NUMBER INTO ITS ROMAN EQUIVALENT              ");
 textcolor(RED);
 cprintf("     ****************************************************************            ");
 textcolor(GREEN+LIGHTGRAY);
 cprintf("\n\n         ENTER ANY NO.");
 textcolor(CYAN);
 cscanf("%d",&n);
 x=n;
 while(n!=0)
  {
   ++j;
   n=n/10;
  }
  n=x;
  while(n!=0)
  {
    r=n%10;
    if(r<5)
     {
      a[i]=r;
      ++i;
      a[i]=0;
     }
    else
     {
      a[i]=r-5;
      ++i;
      a[i]=1;
     }
     n=n/10;
     ++i;
  }
 r=i;
 for(i=0;i<r;++i)
  {
   roman(a[i],al[i]);
  }
 textcolor(GREEN+RED+BLUE+LIGHTGRAY);
 cprintf("\n\n         THE ROMAN EQUIVALENT OF %d IS",x);
 for(i=g;i>=0;--i)
  {
   cprintf("%c",re[i]);
  }
 getch();
 getch();
}
 roman(int a,char c)
  {
   static int j=0;
   int i;
   for(i=0;i<a;++i)
    {
     re[j]=c;
     ++j;
     ++g;
    }
 return;
 }



