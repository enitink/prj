/*FILE NO. 1*/
questionbox_11()
 {
   setlinestyle(0,0,3);
   line(30,250,10,280);
   line(30,250,600,250);
   line(600,250,620,280);
   line(30,310,600,310);
   line(10,280,30,310);
   line(600,310,620,280);
   line(10,280,0,280);
   line(620,280,630,280);

   setfillstyle(1,RED);
   bar(32,252,598,308);
   floodfill(32,252,WHITE);

   return;
 }

answersbox_12()
 {
  int i,j;
  char c[2];

  setlinestyle(0,0,3);
  settextstyle(1,HORIZ_DIR,2);
  setcolor(WHITE);
  setfillstyle(1,BLACK);
  for(i=0;i<=80;i=i+80)
   {
    for(j=0;j<=330;j=j+330)
     {
      line(30+j,340+i,270+j,340+i);
      line(30+j,340+i,10+j,360+i);
      line(30+j,380+i,10+j,360+i);
      line(30+j,380+i,270+j,380+i);
      line(270+j,340+i,290+j,360+i);
      line(290+j,360+i,270+j,380+i);
      line(10+j,360+i,0+j,360+i);
      line(290+j,360+i,330+j,360+i);
      bar(32+j,342+i,270+j,378+i);
      floodfill(32+j,342+i,WHITE);
     }
   }
  extra_21();
  return;
}

sidebox_13()
 {
  static int qun=-1;
  int i,x,y;
  char c[3];
  rectangle(480,10,620,230);
  x=482;
  y=225-(qun*14);
  if(qun>=4)
    y-=4;
  if(qun>=9)
    y-=2;
  if(qun>=12)
    y-=4;
  if(qun>=0)
   {
    setfillstyle(1,GREEN);
    bar(x,y,x+135,y-11);
   }
  x=490;
  y=20;
  settextstyle(2,HORIZ_DIR,4);
  for(i=14;i>0;--i)
   {
    outtextxy(x,y,"QUESTION NO.:");
    itoa(i,c,10);
    outtextxy(x+110,y,c);
    y+=15;
   }
  ++qun;
  return;
 }

pointbox_14()
 {
   int maxx,maxy; 
   static int points=1000;
   char c[9]; 

   maxx=getmaxx();   maxy=getmaxy();

   setfillstyle(1,BLACK);
   bar(0,400,maxx,maxy);

   questionbox_11();

   points*=2;
   itoa(points,c,10);
   settextstyle(1,HORIZ_DIR,2);
   outtextxy(75,265,"CONGRATS MR. U HAVE WON            POINTS");
   outtextxy(370,265,c);

   setfillstyle(1,BLACK);
   bar(32,342,268,378);
   bar(362,342,600,378);
   floodfill(32,342,WHITE);
   floodfill(362,342,WHITE);

   outtextxy(35,345,"RESIGN FROM GAME");
   outtextxy(365,345,"SAVE GAME");
   sleep(2);
   setfillstyle(1,BLACK);
   bar(0,250,maxx,maxy);
  return;
 }

helpbox_15()
 {
   int i=0;

   for(i=0;i<=200;i=i+100)
    {
       setlinestyle(0,0,3);
       circle(90+i,90,50);
    }

  settextstyle(1,HORIZ_DIR,3);

  outtextxy(60,75,"50:50");
  outtextxy(155,65,"PHONE");
  outtextxy(155,95,"  IN ");
  outtextxy(250,65,"PUBLIC");
  outtextxy(250,95," VOTE");

  return;
 }
