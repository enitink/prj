#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.H>

int maxx,maxy,x,y;

void drawchessboard()
{
    int xcor,ycor;

    maxx=getmaxx();
    maxy=getmaxy();

    x=(maxx-20)/8;
    y=(maxy-20)/8;

    for( xcor=10 ; xcor <= maxx-10 ; xcor+=x )
	 line(xcor,10,xcor,maxy-13) ;
    for( ycor=10 ; ycor <= maxy-10 ; ycor+=y )
	 line(10,ycor,maxx-13,ycor);

    return;
}

void knightmove()
{
      int chess[8][8],possmove[8][2];
      int counter=0,currentxpos=0,currentypos=0;
      int ans='y';
      int temp;
      char ch[3];

      for(int i=0; i<8; ++i)
      {
	   for(int j=0; j<8 ; ++j)
		chess[i][j]=0;
	   for(j=0; j<2; ++j)
		possmove[i][j]=-2;
      }

      outtextxy((currentxpos*x)-10,(currentypos*y)-10,"k");

      while(ans!='n' || counter <= 64)
      {

	    if((chess[currentxpos+1][currentypos-2]==0)
	    && (currentxpos+1 <= 8)  && (currentypos-2 > 0))
	    {
		possmove[0][0]=currentxpos+1;
		possmove[0][1]=currentypos-2;
	    }

	    if((chess[currentxpos+2][currentypos-1]==0)
	    && (currentxpos+2 <= 8) && (currentypos-1 > 0))
	    {
		possmove[1][0]=currentxpos+2;
		possmove[1][1]=currentypos-1;
	    }

	    if((chess[currentxpos+2][currentypos+1]==0)
	    && (currentxpos+2 <= 8) && (currentypos+1 <= 8))
	    {
		possmove[2][0]=currentxpos+2;
		possmove[2][1]=currentypos+1;
	    }

	    if((chess[currentxpos+1][currentypos+2]==0)
	    && (currentxpos+1 <= 8) && (currentypos+2 <= 8))
	    {
		possmove[3][0]=currentxpos+1;
		possmove[3][1]=currentypos+2;
	    }

	    if((chess[currentxpos-1][currentypos+2]==0)
	    && (currentxpos-1 > 0) && (currentypos+2 <= 8))
	    {
		possmove[4][0]=currentxpos-1;
		possmove[4][1]=currentypos+2;
	    }

	    if((chess[currentxpos-2][currentypos+1]==0)
	    && (currentxpos-2 > 0) && (currentypos+1 <= 8))
	    {
		possmove[5][0]=currentxpos-2;
		possmove[5][1]=currentypos+1;
	    }

	    if((chess[currentxpos-2][currentypos-1]==0)
	    && (currentxpos-2 > 0) && (currentypos-1 > 0))
	    {
		possmove[6][0]=currentxpos-2;
		possmove[6][1]=currentypos-1;
	    }

	    if((chess[currentxpos-1][currentypos-2]==0)
	    && (currentxpos-1 >0) && (currentypos-2 >0))
	    {
		possmove[7][0]=currentxpos-1;
		possmove[7][1]=currentypos-2;
	    }

	    for( i=0 ; i<8 ; ++i)
	       for(int j=0 ; j<2 ; ++j)
	       {
		 if(possmove[i][j] >= 0)
		 {
		   if((possmove[i][j] != 0) && (possmove[i][j] != 7))
		      temp=i;
		 }
	       }

	    if(temp >=0)
	    {
		++counter;
		itoa(counter,ch,10);
		outtextxy((possmove[temp][0]*x)-10,(possmove[temp][1]*y)-10,ch);
		currentxpos=possmove[temp][0];
		currentypos=possmove[temp][1];
		gotoxy(10,1);
		cout << currentxpos;
		gotoxy(10,2);
		cout << currentypos;
		chess[possmove[temp][0]][possmove[temp][1]]=1;
		getch();
	    }

	     for(i=0 ;i<8 ;++i)
		for(j = 0; j<2 ; ++j)
		   possmove[i][j] = -2;
      }
  chess[0][0]=chess[0][0];
}

void main()
{
	int gd=DETECT,gm;


	clrscr();

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	gotoxy(1,1);
	cout << "Currentxpos=" ;
	gotoxy(1,2);
	cout << "currentypos=" ;

	drawchessboard();
	knightmove();
	getch();
}