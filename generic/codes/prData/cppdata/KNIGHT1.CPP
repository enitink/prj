#include<graphics.h>
#include<conio.h>
#include<iostream.h>

#include<stdlib.h>

int maxx,maxy,x,y;

int getbestmove(int xbox,int ybox)
{
    int bestmove[8][8]={{1,2,3,3,3,3,2,1},
			{2,3,4,4,4,4,3,2},
			{3,4,5,5,5,5,4,3},
			{3,4,5,5,5,5,4,3},
			{3,4,5,5,5,5,4,3},
			{3,4,5,5,5,5,4,3},
			{2,3,4,4,4,4,3,2},
			{1,2,3,3,3,3,2,1}};


    return bestmove[xbox][ybox];

}
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
      int counter=0,currentxpos=7,currentypos=7;
      int temp,temp1=10,temp2=10;
      char ch[3];

      for(int i=0; i<8; ++i)
      {
	   for(int j=0; j<8 ; ++j)
		chess[i][j]=0;
	   for(j=0; j<2; ++j)
		possmove[i][j]=-2;
      }

      outtextxy((currentxpos*x)+20,(currentypos*y)+20,"k");

      while(counter <= 64)
      {

	    if((chess[currentxpos+1][currentypos-2]==0)
	    && (currentxpos+1 < 8)  && (currentypos-2 >= 0))
	    {
		possmove[0][0]=currentxpos+1;
		possmove[0][1]=currentypos-2;
	    }

	    if((chess[currentxpos+2][currentypos-1]==0)
	    && (currentxpos+2 < 8) && (currentypos-1 >= 0))
	    {
		possmove[1][0]=currentxpos+2;
		possmove[1][1]=currentypos-1;
	    }

	    if((chess[currentxpos+2][currentypos+1]==0)
	    && (currentxpos+2 < 8) && (currentypos+1 < 8))
	    {
		possmove[2][0]=currentxpos+2;
		possmove[2][1]=currentypos+1;
	    }

	    if((chess[currentxpos+1][currentypos+2]==0)
	    && (currentxpos+1 < 8) && (currentypos+2 < 8))
	    {
		possmove[3][0]=currentxpos+1;
		possmove[3][1]=currentypos+2;
	    }

	    if((chess[currentxpos-1][currentypos+2]==0)
	    && (currentxpos-1 >= 0) && (currentypos+2 < 8))
	    {
		possmove[4][0]=currentxpos-1;
		possmove[4][1]=currentypos+2;
	    }

	    if((chess[currentxpos-2][currentypos+1]==0)
	    && (currentxpos-2 >= 0) && (currentypos+1 < 8))
	    {
		possmove[5][0]=currentxpos-2;
		possmove[5][1]=currentypos+1;
	    }

	    if((chess[currentxpos-2][currentypos-1]==0)
	    && (currentxpos-2 >= 0) && (currentypos-1 >= 0))
	    {
		possmove[6][0]=currentxpos-2;
		possmove[6][1]=currentypos-1;
	    }

	    if((chess[currentxpos-1][currentypos-2]==0)
	    && (currentxpos-1 >=0) && (currentypos-2 >=0))
	    {
		possmove[7][0]=currentxpos-1;
		possmove[7][1]=currentypos-2;
	    }

	    for(i=0; i<8 ; ++i)
	    {
	       if(possmove[i][0] != -2)
	       {
		  temp1=getbestmove(possmove[i][0],possmove[i][1]);
		  if(temp1 < temp2)
		  {
		     temp2=temp1;
		     temp=i;
		  }
	       }
	    }

	    if(temp >=0)
	    {
		++counter;
		floodfill((possmove[temp][0]*x)+30,(possmove[temp][1]*y)+30,WHITE);
		itoa(counter,ch,10);
		outtextxy((possmove[temp][0]*x)+30,(possmove[temp][1]*y)+30,ch);
		currentxpos=possmove[temp][0];
		currentypos=possmove[temp][1];
		chess[possmove[temp][0]][possmove[temp][1]]=1;
		getch();
	    }

	    temp1=10;
	    temp2=10;

	    for(i=0 ;i<8 ;++i)
	       for(int j = 0; j<2 ; ++j)
		   possmove[i][j] = -2;
      }
}

int main()
{
	int gd=DETECT,gm;

	clrscr();

	initgraph(&gd,&gm,"d:\\tc\\bgi");

	setfillstyle(1,GREEN);
	drawchessboard();
	knightmove();

	closegraph();
	restorecrtmode();

	return 0;
}