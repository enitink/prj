  /* PROGRAM FOR THE FINDING  A NUMBER IS PRIME OR NOT */
#include<stdio.h>
int i,j,n=1,t,m,p,l=0,s;
prnt();
main()
 {
   clrscr();
   printf("\n\t\t\tPROGRAM FOR FINDING A NO. IS PRIME OR NOT\n ");
   printf("\n\nENTER TO WHICH NO. U WANT TO FIND OUT");
   scanf("%d",&m);
   printf("\n\nLIST OF THE PRIME NUMBER'S\n");
   prnt();
   ++n;
   ++p;
   printf("\n\nTOTAL NUMBER OF PRIME NOS.=%d",p);
   printf("\n\n\t\tPRESS ANY KEY TO CONTINUE");
   getch();
   l=0;
   printf("\n\nLIST OF THE NUMBER'S THAT ARE NOT A PRIME NO.\n");
   prnt();
   printf("\n\nTOTAL NUMBER OF NOT PRIME NOS.=%d",t);
   printf("\n\nTOTAL NUMBER OF TERMS FROM WHERE IT IS CALCULATED=%d",p+t);
   getch();
 }

 prnt()
 {
   for(j=2;j<=m;++j)
   {
    i=2;
    while(i<=j-1)
     {
       if(j%i==0)
	{
	 if(n==2)
	  {
	   printf(" %d",j);
	   ++t;
	   ++l;
	  }
	 break;
	}
      i++;
     }
  if(n==1)
   {
    if(i==j)
     {
      printf(" %d",j);
      ++p;
      ++l;
     }
    }
    if(l>12)
    {
     printf("\n\n");
     l=0;
     ++s;
    }
    if(s>19)
    {
     getch();
     clrscr();
     s=0;
    }
   }
   return;
 }
