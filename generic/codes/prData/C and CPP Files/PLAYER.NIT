#include<stdio.h>
typedef struct
 {
  char t[20];
 }player;
 sep();
 player p[50];
 int i=0,n=0,j=0,k=0;
 char name[50][20];
main()
 {
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
  }
 i=0;
 name[0][0]=p[0].t[0];
 for(k=0;k<n;++k)
  {
   j=0;
   sep(j);
  }
 printf("\nThe teams are");
 for(j=0;j<=i;++j)
  printf("\n team %d is %s",j+1,name[j]);
 getch();
}
sep()
{
  if(j<=i)
   {
    if(name[j][0]!=p[k].t[0])
      {
       ++i;
       name[i][0]=p[k].t[0];
      }
    else
      return;
   }
  ++j;
  sep();
}
