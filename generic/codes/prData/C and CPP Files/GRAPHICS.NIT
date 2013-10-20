
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
 void cross(int x,int y);
 char *h[]={
	    "left_text",
	    "center_text",
	    "right_text"
	    };
 char *v[]={
	    "bottom_text",
	    "center_text",
	    "top_text"
	    };

 main()
  {
   int gd=DETECT,gm;
   int midx,midy,i,j;
   char msg[80]="hello,good morning";
   char msg1[80],msg2[80];
   initgraph(&gd,&gm,"c:\\tc\\bgi");
   midx=getmaxx()/2;
   midy=getmaxy()/2;

   for(i=LEFT_TEXT;i<=RIGHT_TEXT;++i)
    {
     for(j=BOTTOM_TEXT;j<=TOP_TEXT;j++)
      {
       cleardevice();
       cross(midx,midy);
       settextjustify(i,j);
       outtextxy(midx,midy,msg);
       settextjustify(LEFT_TEXT,TOP_TEXT);
       outtextxy(100,350,"horizontal justification=");
       sprintf(msg,"%s",h[i]);
       outtextxy(320,350,msg1);
       outtextxy(100,400,"vertical justification=");
       sprintf(msg2,"%s",v[i]);
       outtextxy(320,400,msg2);
      getch();
    }
  }
  closegraph();
  restorecrtmode();
}
void cross(int x,int y)
 {
  line(x-20,y,x+20,y);
  line(x,y-20,x,y+20);
 }