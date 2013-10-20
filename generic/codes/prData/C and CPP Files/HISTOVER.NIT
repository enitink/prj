#include<stdio.h>
#include<graphics.h>

main()
{
 int gd=DETECT,gm;
 int space=0,i,maxx,maxy,no=5,size,j=0;
 int chars[26];
 char chn[3];
 long c;

 space=space;
 for(i=0;i<26;++i)
   chars[i]=0;

 while((c = getchar()) != EOF)
  {
    if(c == ' ')
      ++space;
    c=toupper(c);
    if((c >= 65) && (c <=90))
       chars[c-65] += 1;
  }

 initgraph(&gd,&gm,"c:\tc\bin");

 setbkcolor(BLACK);
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,0);

 maxx=getmaxx();
 maxy=getmaxy();

 line(60,maxy-10,maxx-20,maxy-10);
 line(60,0,60,maxy-10);

 for(i = 100; i <= maxx - 20; i+=40)
  {
     itoa(no,chn,10);
     outtextxy(i+4,maxy-8,chn);
     line(i,maxy-10,i,maxy-8);
     no+=5;
  }

 size=(maxy-30)/26;
 no = 65;

 for(i = (maxy - 10) ; i >= 10; i -=size)
    line(58,i,60,i);
    settextstyle(2,VERT_DIR,0);
    outtextxy(48,0,"Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss TtUu Vv Ww XxYy  Zz");

 j= 35 + (size/2);

 settextstyle(2,HORIZ_DIR,1);

 for(i = 0;i < 26; ++i)
  {
    bar(60,(maxy-15-size-j),60+(chars[i]*8),(maxy-size-j));
    itoa(chars[i],chn,10);
    outtextxy(60+(chars[i]*8),(maxy-13-size),chn);
    j += size;
  }

 settextstyle(0,VERT_DIR,1);
 setcolor(RED);
 outtextxy(30,20,"THE HISTOGRAM FOR ALL THE CHARACTERS THAT WERE ENTERED THROUGH KEYBOARD");
 getch();

/* closegraph();
 restorecrtmode();*/
 j=j;
}
