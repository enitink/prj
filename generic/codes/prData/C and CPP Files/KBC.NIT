#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include"c:\turboc2\kbc_boxs.nit"      /*FILE 1*/
#include"c:\turboc2\kbc_fill.nit"        /*FILE 2*/
#include"c:\turboc2\kbc_ext1.nit"      /*FILE 3*/
#include"c:\turboc2\kbc_ext2.nit"     /*FILE 4*/

main()
 {
    int gd=DETECT,gm,button,x,y;

    initgraph(&gd,&gm,"c:\\tc\\bgi");

    setlinestyle(0,0,3);

    mainmenu_32();

    clrscr();

    setcolor(WHITE);
    settextstyle(1,HORIZ_DIR,2);
    setfillstyle(1,BLACK);
    floodfill(0,0,WHITE);

    sidebox_13();
    settextstyle(1,HORIZ_DIR,2);

    op=fopen("question.dt","rb");
    size1=sizeof(records);

    while((fread(&records,size1,1,op)==1)&&(code!=7))
     {
      helpbox_15();
      questionbox_11();
      xa=32; ya=342;
      k=1;
      answersbox_12();
      checkanswer_31();
      if(result!=1)
	{
	 sleep(1);
	 endbefore_42();
	 exit_45();
	}
      result=0;
      sidebox_13();
      pointbox_14();
      fflush(stdin);
    }
    endlast_43();
 }







