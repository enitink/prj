#include<stdio.h>
typedef struct
 {
  char t[20];
  char n[25];
  float a;
 }player;
main()
 {
  player p[50];
  int i=0,l,n=0,j=0,x=0,k=0,k1=0;
  char name[50][20];
  clrscr();
  printf("\n\t\tPROGRAM FOR PREPARING LIST OF PLAYERS");
  printf("\nenter the no. of players");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
    printf("\n");
    printf("PLAYER NO.:-%d",(i+1));
    printf("\n\tENTER THE NAME OF THE TEAM:-");
    fflush(stdin);
    gets(p[i].t);
    printf("\n\tENTER THE NAME OF THE PLAYER:-");
    fflush(stdin);
    gets(p[i].n);
    printf("\n\tENTER THE BATTING AVG OF THE PLAYER:-");
    scanf("%f",&p[i].a);
  }
 printf("\n\t\t\tTHE PLAYERS ARE");
 printf("\n------------------------------------------------------------------------------");
 printf("\n     sl.no.                PLAYER                       BAT_AVG.");
 printf("\n------------------------------------------------------------------------------");
 name[0][0]=p[0].t[0];
 i=0;
  while(1)
   {
    k1=0;
    for(j=0;j<n;++j)
     {
      x=strncmp(p[j].t[0],name[i][0]);
       if(x==0)
	{
	  if(k1==0)
	    {
	      printf("\n team:- %-17s",p[j].t);
	      ++k1;
	    }
	  printf("\n  %-10d%-37s%f",(k+1),p[j].n,p[j].a);
	  ++k;
	}
	if(k==n)
	 {
	  getch();
	  exit(0);
	 }
     }
    ++i;
    for(j=0;j<i;++j)
     {
      if((i<=n)&&(name[j][0]!=p[i].t[0]))
	x=0;
      else
	x=1;
     }
   }
    if(x==0)
      {
       x=strcmp(p[i].t[0],name[i][0]);
       if(x!=0)
	{
	 name[i][0]=p[i].t[0];
	 k1=0;
	}
      }
}
linkfloat()
 {
  float a=0,*b;
  b=&a;
  a=*b;
 }