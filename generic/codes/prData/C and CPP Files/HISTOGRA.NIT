#include<stdio.h>
#include<graphics.h>

main()
{
 int gd=DETECT,gm;
 int space=0,i,maxx=35,maxy=105,no=5,size,j=0;
 int chars[26];
 char chn[3];
 long c;

 clrscr();

 for(i=0;i<26;++i)
   chars[i]=0;

 printf("\n  PROGRAM FOR PREPARING FREQUENCY HISTOGRAM OF OCCURENCES OF AN ELEMENT IN TEXT");
 printf("\n\n\n              TYPE THE TEXT BELOW(TYPE ^Z TO REPRESENT END OF FILE\n\n\n");

 while((c = getchar()) != EOF)
  {
    if(c == ' ')
      ++space;
    c=toupper(c);
    if((c >= 'A') && (c <='Z'))
       chars[c-'A'] += 1;
  }

 initgraph(&gd,&gm,"c:\tc\bin");
 setbkcolor(BLACK);
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,0);

 maxx=getmaxx();
 maxy=getmaxy();

 line(30,maxy-70,maxx-20,maxy-70);
 line(30,30,30,maxy-70);

 for(i = maxy - 110;i > 30; i-=40)
  {
     itoa(no,chn,10);
     outtextxy(15,i-4,chn);
     line(28,i,30,i);
     no+=5;
  }

 size=(maxx-50)/26;
 no = 65;

 for(i = (30 + size) ; i <= maxx-20; i +=size)
    line(i,maxy-70,i,maxy-67);
    outtextxy(48,maxy-66,"Aa  Bb Cc  Dd  Ee Ff  Gg  Hh  Ii  Jj Kk  Ll  Mm  Nn Oo  Pp Qq  Rr  Ss  Tt  Uu Vv  Ww Xx  Yy  Zz");

 j= 35 + (size/2);

 for(i = 0;i < 26; ++i)
  {
    bar(j,((maxy-70)-(chars[i]*8)),j+(size/2)+2,maxy-70);
    itoa(chars[i],chn,10);
    outtextxy(j,((maxy-84)-(chars[i]*8)),chn);
    j += size;
  }

 settextstyle(0,HORIZ_DIR,1);
 setcolor(RED);
 outtextxy(45,maxy-40,"THE HISTOGRAM FOR ALL THE CHARACTERS THAT WERE ENTERED THROUGH KEYBOARD");
 getch();

 closegraph();
 restorecrtmode();
}
