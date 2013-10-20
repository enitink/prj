#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
  {
    int gd=DETECT,gm,maxx,maxy,midx,midy,corx=0,cory=0,i=0,j=0;
    float x,y,x1,y1,a=-200.0,b=200.0;
    char c[5];

    initgraph(&gd,&gm,"c:\\tc\\bgi");
    maxx=getmaxx();
    maxy=getmaxy();
    midx=maxx/2;
    midy=maxy/2;

    x1=a+2;
    y1=b+2;

/*  outtextxy(70,10,"PROGRAM FOR DRAWING GRAPH OF A FUNCTION");
    outtextxy(100,20,"ENTER THE RANGE  [a,b]  FOR THE FUNCTIOn");*/

    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);

    settextstyle(2,HORIZ_DIR,2);

    i=y1;

    for(x=i;x<=midx;x+=i)
     {
       corx+=10;
       itoa(corx,c,10);
       line(x+midx,midy-2,x+midx,midy+2);
       outtextxy(x+midx-1,midy+3,c);
       itoa(-corx,c,10);
       line(midx-x,midy-2,midx-x,midy+2);
       outtextxy(midx-x-2.5,midy+3,c);
     }

    j=y1;
    for(x=j;x<=midy;x+=j)
     {
       cory+=10;
       itoa(cory,c,10);
       line(midx-2,midy-x,midx+2,midy-x);
       outtextxy(midx+5,midy-x-3.5,c);
       itoa(-cory,c,10);
       line(midx-2,midy+x,midx+2,midy+x);
       outtextxy(midx+5,midy+x-3.5,c);
    }
   /* scanf("%f%f",&a,&b);

    for(x=a;x<=b;x=x+0.5)
      {
	y=cos(x);
	line(x+midx,midy-y,x+midx,midy-y);
      }*/

  getch();
  cory=cory;
  a=a;
  b=b;
/*  closegraph();
  restorecrtmode();*/
}