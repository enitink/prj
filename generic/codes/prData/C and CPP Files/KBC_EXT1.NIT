/*FILE NO 3*/

int result;

checkanswer_31()
 {
   if(records.ans==choice)
       result=1;
   else
      wrongfill_23();
  return;
 }

mainmenu_32()
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

   answersbox_12();
   sleep(2);
   if(choice==2)
     open_44();
   else
     if(choice==4)
       exit_45();
     else
       if(choice==3)
	  howtoplay_34();
   return;
 }

help_33(int keyno)
 {
  int key=0,x1=32,y1=342;

 if(keyno==2)
     x1=362;
    else
     if(keyno==3)
       y1=422;
     else
      if(keyno==4)
	{ x1=362 ; y1=422; }

    setfillstyle(1,BLACK);
    bar(x1,y1,x1+230,y1+36);
    floodfill(x1,y1,WHITE);

  while(key!=28)
   {
     key=getkey_41();
     if(key!=15)
      {
       if(key==77)
	{
	  keyno++;
	  if(keyno>3)
	   keyno=1;
	  fillcircle_25(keyno);
	}
       else
	 if(key==75)
	  {
	    --keyno;
	    if(keyno<1)
	      keyno=3;
	    fillcircle_25(keyno);
	  }
    else
      extra_21();
 }
 }
 return;
}

howtoplay_34()
 {
   clrscr();
   outtextxy(2,2,"i will not tell u");
   sleep(1);
   return;
 }

