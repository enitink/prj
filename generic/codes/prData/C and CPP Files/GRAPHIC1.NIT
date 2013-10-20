#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
main()
  {
   int dri = DETECT,mode;
   initgraph(&dri,&mode,"bgi");
   setcolor(RED);
   textbackground(YELLOW+RED);
   settextstyle(4,HORIZ_DIR,7);
   outtextxy(10,10, " NITIN KUMAR");
    sleep(1);
   settextstyle(4,VERT_DIR,7);
   outtextxy(0,10, " NITIN KUMAR");
    sleep(1);
   settextstyle(4,VERT_DIR,7);
   outtextxy(500,10, " NITIN KUMAR");
    sleep(1);
   settextstyle(4,HORIZ_DIR,7);
   outtextxy(30,400, "NITIN KUMAR");
   getch();
  }
