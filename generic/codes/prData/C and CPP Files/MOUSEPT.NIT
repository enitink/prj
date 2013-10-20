#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<alloc.h>

union REGS i,o;
int maxx,maxy;

mouse()
 {

  int gd=DETECT,gm,x,y,button;

  if(initmouse()==0)
   {
    printf("\nMouse driver not loaded");
    exit(1);
   }

  initgraph(&gd,&gm,"c:\\tc\\bgi");

  maxx=getmaxx();
  maxy=getmaxy();

  restrictmouseptr(0,0,maxx,maxy);

  do
   {
     showmouseptr();
     getmousepos(&button,&x,&y);

   }while((button & 2) !=2);

   gotoxy(65,2);
   printf("X=%03d y=%03d",x,y );

  getch();
  return;
 }

initmouse()
 {
   i.x.ax=0;
   int86(0x33,&i,&o);
   return(o.x.ax);
 }

showmouseptr()
 {
  i.x.ax=1;
  int86(0x33,&i,&o);
 }

/*hidemouseptr()
 {
  i.x.ax=2;
  int86(0x33,&i,&o);
 }*/

restrictmouseptr(int x1,int y1,int x2,int y2)
 {
  i.x.ax=7;
  i.x.cx=x1;
  i.x.dx=x2;
  int86(0x33,&i,&o);

  i.x.ax=8;
  i.x.cx=y1;
  i.x.dx=y2;
  int86(0x33,&i,&o);
 }

getmousepos(int *button,int *x,int *y)
 {
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx;
  *x=o.x.cx;
  *y=o.x.dx;
 }

