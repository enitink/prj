/*****************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

/*****************************************************/



/***************** Gloabal Variables **********************/
float initial_velocity, angle_of_projection,g=9.8; /**/
int h=40,k=450,radius=10;                          /**/
float loc;/*Used to know the location of the tank*//**/
float x1,y1,x2,y2;/*line(x1,y1,x2,y2) for the cannon*/  /**/                        /**/
float maximum;/*maximum velocity allowed*/              /**/
/*for a particular planet*/   /**/
int count;/*Lives*/                                     /**/
int loc_speed=0;/*speed bar location*/                 /**/
int points;/*points*/                               /**/
/**********************************************************/


/******************** FUNCTIONS ***************************/
void rotate(int,int,int,int,int,int,float);             /**/
void wheel(int,int,int);                                /**/
void projectile(float,float,float,int,int);             /**/
int enemy_tank(int turret_x,int turret_y);              /**/
void battlefield(void);                                 /**/
int get_the_initial_x(float);                           /**/
int get_the_initial_y(float);                           /**/
float detect_collision_for_tank(int turret_x,           /**/
int turret_y,float x,float y);      /**/
void blast(int x, int y,float r);                       /**/
void main_menu(void);                                   /**/
void menu_selection(void);                              /**/
void startgame(void);                                   /**/
void game_over(void);        /**/
void select_planet(void);        /**/
void speedbar(void);        /**/
void remove_speedbar(void);                             /**/
void show_instructions(void);        /**/
void credits(void);        /**/
/**********************************************************/


int main(void)
{
	int i=0;
	int gd=VGA,gm=2;
	initgraph(&gd,&gm,"");
	/*THE PATH ABOVE SHOULD BE CHANGED ACCORDINGLY*/
	do
	{
		main_menu();
	}while(i==0);
	return 0;

}

/*STARTS THE GAME*/
void startgame(void)
{

	select_planet();
	show_instructions();
	count=10;/*NUMBER OF LIVES*/
	points=0;
	randomize();
	battlefield();
	setlinestyle(0,0xFFFF,3);
	setcolor(15);
	line(h-radius*1.5,k,h+radius*2.5,k);
	rotate(h-radius*1.5,k,h+radius*2.5,k,h,k,radius);
	x1=y1=x2=y2=0;

}


/*DRAWS A WHEEL AT (h,k) OF RADIUS "radius"*/
void wheel (int h,int k, int radius)
{
	int slice;
	circle(h,k,radius/2.5);

	setfillstyle(EMPTY_FILL,15);

	for (slice=0;slice<=360;slice+=45)
	{
		pieslice(h,k,slice,slice+45,radius);

	}
}

/*NOT ONLY ROTATES BUT ALSO TAKES INSTRUCTIONS
TO INVOKE THE SPEEDBAR() AND PROJECTILE()*/
void rotate(int a1,int b1,int a2,int b2,
int h,int k,float radius)
{
	char c;
	char cnt[3];
	float added,rotate_rad;
	angle_of_projection=0.0;
	added=0.0;
	setlinestyle(0,0xFFFF,1);
	while((c=getch())!=27)
	{

		/***HERE THE ANGLE OF PROJECTION GETS COMPUTED***/
		/**/if(c==0)                                  /**/
		/**/{                                         /**/
			/**/c=getch();                            /**/
			/**/if(c==72 && angle_of_projection<=180) /**/
			/**/{added=added+.05;              /**/
				/**/angle_of_projection+=added;   /**/
				/**/}                                     /**/
			/**/if(c==80 && angle_of_projection>=0)   /**/
			/**/{added=added+.05;              /**/
				/**/angle_of_projection-=added;   /**/
				/**/}                                     /**/
			/**/                                          /**/
			/**/}                                         /**/
		/************************************************/
		rotate_rad=angle_of_projection*3.141592/180;
		setcolor(0);
		setlinestyle(0,0xFFFF,3);
		line(a1,b1,a2,b2);
		line(x1,y1,x2,y2);
		x1=h-cos(rotate_rad)*pow(((h-a1)*(h-a1)+(k-b1)*(k-b1)),.5);
		y1=k+sin(rotate_rad)*pow(((h-a1)*(h-a1)+(k-b1)*(k-b1)),.5);
		x2=h+cos(rotate_rad)*pow(((h-a2)*(h-a2)+(k-b2)*(k-b2)),.5);
		y2=k-sin(rotate_rad)*pow(((h-a2)*(h-a2)+(k-b2)*(k-b2)),.5);
		setcolor(15);
		line(x1,y1,x2,y2);
		line(h-radius*3,k+radius*1.25,640,k+radius*1.25);
		setlinestyle(0,0xFFFF,1);
		wheel(h,k,radius);

		if(c=='z')
		/*HERE THE eINITIAL VELOCITY GETS COMPUTED*/
		/**/ speedbar();                  /**/
		/*****************************************/
		if(c=='x')
		{

			remove_speedbar();
			setcolor(0);
			sprintf(cnt,"%i",count);
			outtextxy(620,20,cnt);
			outtextxy(10,10,"Ready to fire");
			setcolor(4);
			outtextxy(10,10,"Loading Ammunition...");
			sound(1000);
			delay(70);
			nosound();
			/*HERE WE PROVIDED THE PROJECTILE() WITH NECESSARY VALUES*/
			projectile(initial_velocity,angle_of_projection,g,
			get_the_initial_x(angle_of_projection),
			get_the_initial_y(angle_of_projection));

			setcolor(0);
			outtextxy(10,10,"Loading Ammunition...");
			setcolor(2);
			outtextxy(10,10,"Ready to fire");
			setcolor(15);
			sprintf(cnt,"%i",count);
			outtextxy(620,20,cnt);
			initial_velocity=5;
			loc_speed=0;

		}
		if (count==0)/*ALL LIVES GONE*/
		{
			game_over();
			break;
		}
	}

}

/*THIS WHERE THE PROJECTILE IS GUIDED TO ITS PATH*/
void projectile(float initial_velocity,float angle_of_projection,float g,
int initial_x,int initial_y)
{


	float collision;
	float t,a_rad,x=0,y=0;
	a_rad=angle_of_projection*3.141592/180;

	for(t=0;y>=-initial_y && x<=640 && x>=0;t=t+.01)
	{

		x=(initial_velocity*cos(a_rad)*t);
		y=(initial_velocity*sin(a_rad)*t)-(0.5*g*t*t);
		collision=detect_collision_for_tank(loc,k-20,x,y);
		if (collision <=0)
		{
			blast(initial_x+x,initial_y-y,20);
			blast(initial_x+x+10,initial_y-y+3,20);
			blast(initial_x+x+20,initial_y-y+5,20);
			points++;
			if(points>1 && points%25==0)
			/*INCREASES LIFE AFTER EVERY 25 SUCCESSFUL HITS*/
			{
				sound(440);
				delay(1000);
				count++;
				nosound();
			}
			if(angle_of_projection>=60)
			/*INCREASES LIFE IF ANGLE>=60 HITS*/
			{
				count=count++;
				sound(640);
				delay(1000);
				nosound();
			}
			battlefield();
			break;
		}
		setcolor(14);
		circle(initial_x+x,initial_y-y,2);
		setfillstyle(SOLID_FILL,14);
		floodfill(initial_x+x,initial_y-y,14);
		delay(1);
		setcolor(0);
		circle(initial_x+x,initial_y-y,2);
		setfillstyle(SOLID_FILL,0);
		floodfill(initial_x+x,initial_y-y,0);

	}

	if (collision>0)
	/*NO COLLISION NO POINTS BUT LESS LIVES*/
	count--;



}

/*DRAWS THE ENEMY TANK AT RANDOM POSITIONS*/
int enemy_tank(int turret_x,int turret_y)
{
        int c=4;
        int i;
        setlinestyle(0,0xFFFF,1);
        setcolor(c);
        /*TURRET*/rectangle(turret_x,turret_y,turret_x+8,turret_y+2);
        /*HEAD*/  rectangle(turret_x+8,turret_y-3,turret_x+16,turret_y+6);
        /*BODY*/  rectangle(turret_x-8,turret_y+6,turret_x+32,turret_y+24);
        setfillstyle(HATCH_FILL,c);
        floodfill(turret_x+8+1,turret_y-3+1,c);
        setfillstyle(SOLID_FILL,c);
        floodfill(turret_x-8+1,turret_y+6+1,c);
        floodfill(turret_x+1,turret_y+1,c);
        for(i=0;i<=24;i=i+6)
        wheel(turret_x+i,turret_y+25,5);

        return turret_x;
}

/*INITIALIZES THE GAME SCREEN*/
void battlefield(void)
{
        char p[3];
        char cnt[3];
        cleardevice();
        setcolor(15);
        outtextxy(550,10,"Kills: ");
        sprintf(p,"%i",points);
        outtextxy(620,10,p);
        outtextxy(550,20,"Lives: ");
        sprintf(cnt,"%i",count);
        outtextxy(620,20,cnt);
        wheel (h,k,radius);
        setlinestyle(0,0xFFFF,3);
        line(h-radius*3,k+radius*1.25,640,k+radius*1.25);
        if (count>0) line(x1,y1,x2,y2);
        loc=enemy_tank(h+100+random(470),k-20);
}


/*RETURNS THE X-VALUE FROM WHERE THE PROJECTILE SHOULD BE SHOT*/
int get_the_initial_x(float a)
{
        int initial_x;
        initial_x=h+cos(a*3.141592/180)
        *pow(((h-h+radius*2.5)*(h-h+radius*2.5)+(k-k)*(k-k)),.5);
        return initial_x+2.5;
}
/*RETURNS THE Y-VALUE FROM WHERE THE PROJECTILE SHOULD BE SHOT*/
int get_the_initial_y(float a)
{
        int initial_y;
        initial_y=k-sin(a*3.141592/180)
        *pow(((h-h+radius*2.5)*(h-h+radius*2.5)+(k-k)*(k-k)),.5);
        return initial_y-2.5;
}

/*RETURNS 0 OR NEGATIVE VALUE IF A COLLISION IS DETECTED*/
float detect_collision_for_tank(int turret_x,int turret_y,float x,float y)
{
        float a,b,r;
        float collision;
        a=((turret_x-8)+(turret_x+32))/2;
        b=((turret_y+6)+(turret_y+24))/2;
        r=20; //((turret_x+32)-(turret_x-8))/2
        collision=pow((get_the_initial_x(angle_of_projection)+x-a),2)+
        pow((get_the_initial_y(angle_of_projection)-y-b),2)-
        pow(r,2);
        return collision;
}

/*THE EXPLOSION*/
void blast(int x, int y,float r)
{
        float i;
        for(i=0;i<=r;i=i+.1)
        {

                setcolor(14);
                circle(x,y,i);
                sound(1000);
                delay(1);
                setcolor(0);
                circle(x,y,i);
                nosound();
        }

}

/*ONLY DRAWS THE MAIN MENU*/
void main_menu(void)
{
        int x=0,y=0,length=120,width=20,i=0;
        int outline=2;
        int no_menu_items=2;
        int distance=5;
        int gaps=width + distance;
        char *item[]={"(S)tart","(C)redits","(E)xit"};
        cleardevice();
        setcolor(15);
        x=(640-length)/2;
        y=(480-(no_menu_items+1) * gaps)/2;
        for(i=0;i < no_menu_items;i++)
        {

                rectangle(x,y,x+length,y+width);
                rectangle(x+outline,y+outline,x+length-outline,y+width-outline);
                outtextxy(x+10,y+6,item[i]);
                y+=gaps;

        }

        rectangle(x,y+gaps,x+length,y+width+gaps);
        rectangle(x+outline,y+gaps+outline,x+length-outline,y+width+gaps-outline);
        outtextxy(x+10,y+gaps+6,item[i]);
        settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
        outtextxy(180,50,"Projectile");
        settextstyle(0,HORIZ_DIR,1);
        outtextxy(320,120,">>>>>>>>>>>>>>>>>>>");
        menu_selection();
}

/*SELECTS APPROPIATE FUNCTIONS*/
void menu_selection(void)
{
        char ch;
        ch=getch();

        switch (ch)
        {
                case 's':   startgame();break;
                case 'e':   closegraph();exit(1);
                case 'c':   credits();break;
                default: ;

        }
}


/*SHOWS "Game Over" AND HALTS THE PROGRAM FOR 3 SECONDS*/
void game_over(void)
{
        outtextxy(250,220,"Game Over");
        sleep(3);

}

/*CHANGES GRAVITY(g) AND SETS THE MAXIMUM SPEED ALLOWED*/
void select_planet(void)
{
        char ch;
        int x,y,length=190,width=20,i=0;
        int outline=2;
        int no_menu_items=8;
        int distance=10;
        int gaps=width + distance;
        char *item[]={"1.Pluto(g=0.66)","2.Moon(g=1.62)","3.Mercury/Mars(g=3.7)"
                ,"4.Uranus/Venus(g=8.87)"
                ,"5.Earth(g=9.81)","6.Saturn(g=10.4)"
                ,"7.Neptune(9=11.15)","8.Jupiter(g=24.8)"};

        cleardevice();
        setcolor(15);
        x=(640-length)/2;
        y=(480-(no_menu_items+1) * gaps)/2;
        setcolor(2);
        outtextxy(50,50,"Select a Planet/satellite");
        setcolor(15);
        for(i=0;i < no_menu_items;i++)
        {

                rectangle(x,y,x+length,y+width);
                rectangle(x+outline,y+outline,x+length-outline,y+width-outline);
                outtextxy(x+10,y+6,item[i]);
                y+=gaps;

        }
        ch=getch();
        if(ch==0)getch();
        switch(ch)
        {
                case '1':  g = 0.660;maximum=25;break;
                case '2':  g = 1.620;maximum=50;break;
                case '3':  g = 3.710;maximum=60;break;
                case '4':  g = 8.870;maximum=90;break;
                case '5':  g = 9.810;maximum=100;break;
                case '6':  g = 10.40;maximum=110;break;
                case '7':  g = 11.15;maximum=120;break;
                case '8':  g = 24.80;maximum=150;break;
                default:   g = 9.810;maximum=100;break;
        }

}

/*INCREASES SPEED BY 5 AND PUTS A BAR ON THE SCREEN*/
void speedbar(void)
{
        char c[5];
        if (initial_velocity<maximum)
        {
                initial_velocity+=5;
                loc_speed=loc_speed+10;
                if (initial_velocity/maximum*100<=50) setcolor(2);/*GREEN*/
                if (initial_velocity/maximum*100 > 50
                && initial_velocity/maximum*100 < 90)
                setcolor(14);/*YELLOW*/
                if (initial_velocity/maximum*100>=90) setcolor(4);/*RED*/
                sprintf(c,"%c",254);
                outtextxy(20+loc_speed,470,c);
        }

}

/*REMOVES ALL THE BARS DRAWN BY THE SPEEDBAR()*/
void remove_speedbar(void)
{
        int j;
        char c[5];
        loc_speed=0;
        setcolor(0);
        for(j=0;j < maximum;j++)
        {
                loc_speed=loc_speed+10;

                sprintf(c,"%c",254);
                outtextxy(20+loc_speed,470,c);
        }

}

/*SHOWS HOW TO PLAY*/
void show_instructions(void)
{
        char temp[2];
        char ch;
        cleardevice();
        moveto(200,200);
        outtext("Use ");
        sprintf(temp,"%c",24);
        outtext(temp);
        outtext(" and ");
        sprintf(temp,"%c",25);
        outtext(temp);
        outtext(" keys to rotate the cannon");
        ch=getch();
        if(ch==0) getch();
        cleardevice();
        outtextxy(180,200,"Use z to set the speed and press x to shoot");
        getch();
}

/*RUNS THE CREDITS*/
void credits(void)
{
        cleardevice();
        outtextxy(150,140,"**************************************************");
        outtextxy(180,160,"Programmed by");
        outtextxy(240,180,"Shahbaz Rahman");
        outtextxy(240,200,"ID# 041 061 040");
        outtextxy(240,220,"CSE Department, North South University");
        outtextxy(180,240,"AND");
        outtextxy(240,260,"Kazi Asif Wadud");
        outtextxy(240,280,"ID# 041 242 040");
        outtextxy(240,300,"CSE Department, North South University");
        outtextxy(150,320,"**************************************************");
        outtextxy(240,340,"                 2004-2005");
        getch();

}