#include<stdio.h>

int m,y,nd[]={31,28,31,30,31,30,31,31,30,31,30,31},dat[5][7];
int l=0;
void month();
void year();
void cal();
void date();
char *days[]={
	      "MONDAY","TUESDAY",
	      "WEDNENDAY","THURSDAY",
	      "FRIDAY","SATURDAY","SUNDAY"
	     },
     *mon[]={ "JANUARY","FEBRUARY",
	      "MARCH","APRIL","MAY",
	      "JUNE","JULY","AUGUST",
	      "SEPTEMBER","OCTOBER",
	      "NOVEMBER","DECEMBER" };
int main()
 {
   int i,j;
   printf("\n======================PROGRAM FOR PRINTING OUT CALENDAR OF A MONTH======================");
   printf("========================================================================");
   month();
   year();
   cal();
   date();
   printf("\n\n\n         %-16s   %d \n\n ",mon[m-1],y);
   for(i=0;i<6;++i)
    printf("%-7s ",days[i]);
    printf("%-7s ",days[6]);
   for(i=0;i<5;++i)
    {
     printf("\n");
     for(j=0;j<7;++j)
      {
       if(j==7)
	{
	  printf("%7d ",dat[i][j]);
	}
	printf("%7d ",dat[i][j]);
    }
 }
	return 0;
}
void month()
  {
   printf("\nENTER MONTH AS AN INT(1 TO 12)");
   scanf("%d",&m);
    if((m>12)||(m<1))
      {
       printf("\nINVALID YEAR(ENTER BETWEEN 1 TO 12)");
       month();
      }
  }
void year()
  {
   printf("\nENTER YEAR AS AN INT(1900 TO 2100)");
   scanf("%d",&y);
   if((y>2100)||(y<1900))
     {
      printf("\nINVALID MONTH(ENTER BETWEEN 1 TO 12)");
      year();
     }
   return;
  }
void cal()
  {
   int i,td=0,d;
   long  int d1;
   for(i=1899;i<y;++i)
    {
     if(i%4==0)
       ++l;
    }
   if(m>=3)
    ++l;
   for(i=0;i<m-1;++i)
     td=td+nd[i];
   d1=y-1900;
   d1=d1*365;
   d1=d1+l+td;
   l=d1%7;
   if (y==1900)
    l=1;
   if (l==0)
    l=7;
   return;
  }
void date()
  {
   int i,j,r=1,td=0;
    td=nd[m-1];
   if((y%4==0)&&(m==2))
    ++td;
   for(i=0;i<5;++i)
    {
     for(j=0;j<7;++j)
      {
       dat[i][j]=0;
      if(r<=td)
       {
	if(i==0)
	 {
	  if(j>=l-1)
	   {
	    dat[i][j]=r;
	    ++r;
	   }
	 }
       if((i>0)&&(i<5))
	 {
	  dat[i][j]=r;
	  ++r;
	 }
       }
      }
    }
  return;
 }
