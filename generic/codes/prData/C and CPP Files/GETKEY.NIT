#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include"c:\turboc2\mousept.nit"
union REGS i,o;
int button=0,key;

main()
 {
   int gd=DETECT,gm;

   char ans='y';

   initgraph(&gd,&gm,"c:\\tc\\bgi");

   while(ans!='n')
   {
     printf("\npress any key");
     key=getkey();
     printf("\nthe entered key is has scan code %d\n and button pressed %d \n do want to continue(y/n)",key,button);
     ans=getche();
     ans=tolower();
   }
 }

getkey()
 {
  while(!kbhit()||((button & 1)==0)||((button & 2)==0))
    button=mouse();
  i.h.ah=0;
  int86(22,&i,&o);
  key=o.h.ah;
  gotoxy(30,130);
  printf("%d",button);
  getch();
  return;
 }