/*FILE NO 2*/
#include<stdio.h>

typedef struct
 {
  char question[80];
  char ans1[20];
  char ans2[20];
  char ans3[20];
  char ans4[20];
  int ans;
 }data;

data records={"                       ","PLAY GAME",
	      "PLAY SAVED GAME","HOW TO PLAY","QUIT",1};

int choice,code,k,xa=32,ya=342,size1;
FILE *op;


extra_21()
 {

   int key=0,keyno=1;
   char c[2];
   static int i=1;

   setfillstyle(1,GREEN);
   floodfill(32,342,WHITE);

   do
    {
       writeqans_24();

       key=getkey_41();

       if((key==15)&&(i!=1))
	 help_33(keyno);
       else
	{
	 if(key==77)
	  {
	   ++keyno;
	   if(keyno>4)
	     keyno=1;
	   fillfun_22(keyno);
	  }
	 else
	  if(key==75)
	   {
	    --keyno;
	    if(keyno<1)
	     keyno=4;
	    fillfun_22(keyno);
	   }
	  else
	    if(key==72)
	     {
	      keyno+=2;
	      if(keyno>4)
		keyno=1;
	      fillfun_22(keyno);
	     }
	    else
	      if(key==80)
	       {
		keyno-=2;
		if(keyno<1)
		 keyno=4;
		fillfun_22(keyno);
	       }
	}
      }while(key!=28);
   ++code;
   choice=keyno;
   op=op;
   ++i;
   return;
 }

fillfun_22(int keyno)
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

wrongfill_23()
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
    writeqans_24();
    sleep(1);
   return;
 }
writeqans_24()
 {
    outtextxy(35,265,records.question);
    outtextxy(35,345,records.ans1);
    outtextxy(365,345,records.ans2);
    outtextxy(35,425,records.ans3);
    outtextxy(365,425,records.ans4);
    return;
 }

fillcircle_25(int n)
 {
   int x=60,y=70;

   if(n==2)
     x=130;
   else
     x=230;
   setfillstyle(1,GREEN);
   floodfill(x,y,WHITE);
   return;
 }