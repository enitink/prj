
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

 main()
  {
   int gd=DETECT,gm,maxx,maxy,n=0,i=0;
   int midx,midy;
   initgraph(&gd,&gm,"c:\\tc\\bgi");

   maxx=getmaxx();
   maxy=getmaxy();
   midx=maxx/2;

   while(n!=10000)
    {
     setlinestyle(2,0,3);
     setcolor(WHITE);
     line(midx-50,i,midx-50,10);
     line(midx+50,i,midx+50,10);
     delay(2);
     ++n;
     ++i;
    }

   maxy=maxy;
   getch();
   closegraph();
   restorecrtmode();
}
