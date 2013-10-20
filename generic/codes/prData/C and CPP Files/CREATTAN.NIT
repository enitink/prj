#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
  {
    int gd=DETECT,gm,maxx,maxy,midx,midy,corx=0,cory=0;
    int x,y,x1;
    float cosx,val,val1;
    char c[10];

    initgraph(&gd,&gm,"c:\\tc\\bgi");
    maxx=getmaxx();
    maxy=getmaxy();
    midx=maxx/2;
    midy=maxy/2;

    outtextxy(70,10,"PROGRAM FOR DRAWING GRAPH OF FUNCTION Tan(X)");

    line(0,midy,maxx,midy);
    line(midx,0,midx,maxy);

    settextstyle(2,HORIZ_DIR,2);

    for( x= midx+90 , x1= midx-90 ; x<=maxx; x+=90 , x1-=90)
     {
       corx+=90;
       itoa(corx,c,10);
       line(x,midy-2,x,midy+2);
       outtextxy(x-1,midy+3,c);
       itoa(-corx,c,10);
       line(x1,midy-2,x1,midy+2);
       outtextxy(x1-2.5,midy+3,c);
     }

    for( x = midy-100 , x1 = midy+100 ;  x>=0 ; x -= 100 , x1 += 100)
     {
       cory+=5;
       itoa(cory,c,10);
       line(midx-2,x,midx+2,x);
       outtextxy(midx+5,x-3.5,c);
       itoa(-cory,c,10);
       line(midx-2,x1,midx+2,x1);
       outtextxy(midx+5,x1-3.5,c);
    }

    for(val = -midx ; val <= midx ; val += .001)
     {
       val1=val*3.141592/180;
       cosx=tan(val1);

       line(val+midx,midy-(cosx*30),val+midx,midy-(cosx*30));
     }
  getch();
/*  closegraph();
  restorecrtmode();*/
}

linkfloat()
 {
  float a=0,*b;
  b=&a;
  a=*b;
 }