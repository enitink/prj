#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

typedef struct
 {
  char question[80];
  char ans1[20];
  char ans2[20];
  char ans3[20];
  char ans4[20];
  int ans;
 }data;

typedef struct
 {
   char username[25];
   char password[20];
   int an;
 }userfile;

questionbox_1();
answersbox_2();
fillfun_3(int a);
getkey_4();
checkanswer_5();
wrongfill_6();
sidebox_8();
mainmenu_9();
writeqans_10();
endbefore_11();
endlast_12();
open_13();
pointbox_14();
helpbox_15();
help_16();
howtoplay_17();
exit_20();

FILE *op,*up;
int choice,result,code,size1,size2,maxx,maxy,position,xa,ya,k;
data records={"                       ","PLAY GAME",
	      "PLAY SAVED GAME","HOW TO PLAY","QUIT",1};

main()
 {
    int gd=DETECT,gm;

    initgraph(&gd,&gm,"c:\\tc\\bgi");

    maxx=getmaxx();
    maxy=getmaxy();

    size1=sizeof(records);
    op=fopen("question.dt","rb");

    setlinestyle(0,0,3);

    mainmenu_9();

    clrscr();
    setcolor(WHITE);
    settextstyle(1,HORIZ_DIR,2);
    setfillstyle(1,BLACK);
    floodfill(0,0,WHITE);

    sidebox_8();
    settextstyle(1,HORIZ_DIR,2);
    while((fread(&records,size1,1,op)==1)&&(code!=7))
     {
      helpbox_15();
      questionbox_1();
      xa=32; ya=342;
      k=1;
      answersbox_2();
      checkanswer_5();
      if(result!=1)
	{
	 sleep(1);
	 endbefore_11();
	}
      result=0;
      sidebox_8();
      pointbox_14();
      fflush(stdin);
    }
    endlast_12();
 }

questionbox_1()
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

answersbox_2()
 {
  int i,j,key=0,keyno=1;
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

     setfillstyle(1,GREEN);
     floodfill(32,342,WHITE);

   do
    {
      writeqans_10();

      key=getkey_4();
      if(key==15)
	 help_16();
      else
       {
	if(key==77)
	 {
	  ++keyno;
	  if(keyno>4)
	    keyno=1;
	  fillfun_3(keyno);
	 }
	else
	 if(key==75)
	  {
	   --keyno;
	   if(keyno<1)
	     keyno=4;
	   fillfun_3(keyno);
	  }
	 else
	   if(key==72)
	    {
	     keyno+=2;
	     if(keyno>4)
	       keyno=1;
	     fillfun_3(keyno);
	    }
	   else
	     if(key==80)
	      {
	       keyno-=2;
	       if(keyno<1)
		keyno=4;
	       fillfun_3(keyno);
	      }
       }
     }while(key!=28);
   ++code;
   choice=keyno;
   return;
 }

fillfun_3(int keyno)
 {
  static int x1=32,y1=342;
  int x=32,y=342;
  if(k==1)
    {x1=xa; y1=ya;}
  k=0;
  setfillstyle(1,BLACK);
  bar(x1,y1,x1+230,y1+36);
  floodfill(x1,y1,WHITE);

    if(keyno==2)
     x=362;
    else
     if(keyno==3)
       y=422;
     else
      if(keyno==4)
	{ x=362 ; y=422; }

  setfillstyle(1,GREEN);
  bar(x,y,x+230,y+36);
  floodfill(x,y,WHITE);

  x1=x; y1=y;
  return;
 }

getkey_4()
 {
  union REGS i,o;
  while(!kbhit())
    ;
  i.h.ah=0;
  int86(22,&i,&o);
  return(o.h.ah);
 }

checkanswer_5()
 {
   if(records.ans==choice)
       result=1;
   else
      wrongfill_6();
  return;
 }

wrongfill_6()
 {
   int i,x=32,y=342;
   char c1[3];

   if(choice==2)
      x=362;
   else
     if(choice==3)
       y=422;
     else
       if(choice==4)
	{ x=362; y=422; }
    setfillstyle(1,RED);
    bar(x,y,x+230,y+36);
    floodfill(x,y,WHITE);

    x=32; y=342;
    if(records.ans==2)
      x=362;
    else
     if(records.ans==3)
       y=422;
     else
      if(records.ans==4)
	{ x=362 ; y=422; }
    setfillstyle(1,GREEN);
    bar(x,y,x+230,y+36);
    floodfill(x,y,WHITE);
    writeqans_10();
    sleep(1);
   return;
 }

sidebox_8()
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

mainmenu_9()
 {
   settextstyle(4,HORIZ_DIR,7);
   setfillstyle(1,LIGHTGRAY);
   bar(10,50,610,150);
   setcolor(BLACK);
   outtextxy(35,55,"NITIN KUMAR'S");
   settextstyle(1,HORIZ_DIR,7);
   bar(220,210,400,310);
   setcolor(BLACK);
   outtextxy(225,225," KBC ");
   answersbox_2();
   sleep(1);
   if(choice==2)
     open_13();
   else
     if(choice==4)
       exit_20();
     else
       if(choice==3)
	  howtoplay_17();
   return;
 }

writeqans_10()
 {
    outtextxy(35,265,records.question);
    outtextxy(35,345,records.ans1);
    outtextxy(365,345,records.ans2);
    outtextxy(35,425,records.ans3);
    outtextxy(365,425,records.ans4);
   return;
 }

endbefore_11()
 {
   clrscr();
   setfillstyle(1,BLACK);
   bar(0,0,maxx,maxy);
   questionbox_1();
   outtextxy(75,265,"SORRY YOU HAVE GIVEN THE WRONG ANSWER");
   sleep(1);
   closegraph();
   restorecrtmode();
   return;
 }

endlast_12()
 {
  clrscr();
  setfillstyle(1,BLACK);
  bar(0,0,maxx,maxy);
  questionbox_1();
  settextstyle(1,HORIZ_DIR,2);
  outtextxy(75,265,"CONGRATS U HAVE GOT ALL THE ANSWERS RIGHT");
  sleep(1);
  closegraph();
  restorecrtmode();
  return;
 }

open_13()
 {
   int x,y;
   userfile user,entered;
   up=fopen("userrecord","ab+");
   setfillstyle(1,BLACK);
   bar(0,0,maxx,maxy);
   setfillstyle(1,LIGHTGRAY);
   x=maxx/2; y=maxy/2;
   bar(x-100,y-50,x+100,y+50);
   getch();
   return;
  }

pointbox_14()
 {
  static int points=1000;
  char c[9];

  setfillstyle(1,BLACK);
  bar(0,400,maxx,maxy);

  questionbox_1();

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

help_16()
 {
  int key=0,keyno=0;

  while(key!=28)
   {
     key=getkey_4();
     if(key!=15)
      {
       if(key==77)
	{
	  keyno++;
	  if(keyno>3)
	   keyno=1;
	  fillcircle_18(keyno);
	}
       else
	 if(key==75)
	  {
	    --keyno;
	    if(keyno<1)
	      keyno=3;
	    fillcircle_18(keyno);
	  }
   else
     break;
 }
 }
 return;
}
howtoplay_17()
 {
   clrscr();
   outtextxy(2,2,"i will not tell u");
   sleep(1);
   return;
 }

fillcircle_18(int n)
 {
   int x=60,y=70;

   if(n==2)
     x=130;
   else
     x=230;
   setfillstyle(1,GREEN);
   floodfill(x,y,WHITE);
   return;
 }
exit_20()
 {
  clrscr();
  closegraph();
  restorecrtmode();
  exit(0);
 }

