#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<alloc.h>

union REGS i,o;

main()
 {

  int gd=DETECT,gm,maxx,maxy,x=38,y=38,button,area;
  char *buff,*buff1;

  initgraph(&gd,&gm,"c:\\tc\\bgi");
  maxx=getmaxx();
  maxy=getmaxy();

  setfillstyle(SOLID_FILL,RED);
  circle(40,40,2);
  floodfill(40,40,WHITE);

  area=imagesize(38,38,42,42);
  buff=malloc(area);
  getimage(38,38,42,42,buff);

  setfillstyle(SOLID_FILL,BLACK);
  bar(38,38,42,42);

  area=imagesize(38,38,42,42);
  buff1=malloc(area);
  getimage(38,38,42,42,buff1);

  rectangle(0,56,maxx,maxy);
  setviewport(1,57,maxx-1,maxy-1,1);

  gotoxy(26,1);
  printf("Mouse demonstration Program");

  if(initmouse()==0)
   {
    closegraph();
    restorecrtmode();
    printf("\nMouse driver not loaded");
    exit(1);
   }

   restrictmouseptr(1,1,maxx-7,maxy-62);

   gotoxy(1,2);
   printf("Left Button");
   gotoxy(15,2);
   printf("Right Button");
   gotoxy(55,3);
   printf("Press any key to exit...");
   fflush(stdin);

   while(!kbhit())
    {
      putimage(x,y,buff1,COPY_PUT);

      getmousepos(&button,&x,&y);

      putimage(x,y,buff,XOR_PUT);
      delay(0);

      gotoxy(5,3);
      (button & 1) == 1? printf("DOWN"):printf("UP");

      gotoxy(20,3);
      (button & 2) == 2? printf("DOWN"):printf("UP");

      gotoxy(65,2);
      printf("X=%03d y=%03d",x,y );
     }
  }

initmouse()
 {
   i.x.ax=0;
   int86(0x33,&i,&o);
   return(o.x.ax);
 }

/*showmouseptr()
 {
  i.x.ax=1;
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