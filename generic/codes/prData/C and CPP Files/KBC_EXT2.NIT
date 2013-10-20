/*FILE NO 4*/

int maxx,maxy;

typedef struct
 {
   char username[25];
   char password[20];
   int an;
 }userfile;

getkey_41()
 {
  union REGS i,o;
  while(!kbhit())
   ;
  i.h.ah=0;
  int86(22,&i,&o);

  sound(320);
  delay(5);
  nosound();

  return(o.h.ah);
}

endbefore_42()
 {
   maxx=getmaxx(); maxy=getmaxy();

   clrscr();
   setfillstyle(1,BLACK);
   bar(0,0,maxx,maxy);
   questionbox_11();
   outtextxy(75,265,"SORRY YOU HAVE GIVEN THE WRONG ANSWER");
   sleep(1);
   closegraph();
   restorecrtmode();
   return;
 }

endlast_43()
 {
  clrscr();
  setfillstyle(1,BLACK);
  bar(0,0,maxx,maxy);
  questionbox_11();
  settextstyle(1,HORIZ_DIR,2);
  outtextxy(75,265,"CONGRATS U HAVE GOT ALL THE ANSWERS RIGHT");
  sleep(1);
  closegraph();
  restorecrtmode();
  return;
 }

open_44()
 {
  FILE *up;
   int x,y;
   userfile user,entered;

   up=fopen("userrecord","ab+");
   setfillstyle(1,BLACK);
   bar(0,0,maxx,maxy);
   setfillstyle(1,LIGHTGRAY);
   x=maxx/2; y=maxy/2;
   bar(x-100,y-50,x+100,y+50);
   getch();
   up=up;
   return;
  }

exit_45()
 {
  clrscr();
  closegraph();
  restorecrtmode();
  exit(0);
 }