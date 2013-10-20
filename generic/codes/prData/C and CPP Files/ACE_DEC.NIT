#include<stdio.h>
#include<graphics.h>
#include<conio.h>
sort(int *p,int n,int c);
acending(int *p);
decending(int *p);
main()
 {
  int choice,n,i,*p;
  clrscr();
  printf("\n\t\tPROGRAM FOR SORTING GIVEN NUMBERS IN ACENDING ORDER");
  printf("\n\nENTER THE NUMBER OF TERMS U WANT TO INPUT");
  scanf("%d",&n);
  if(n<=1)
    printf("\n\nSORTING IS NOT POSSIBLE IN THIS CASE");
  else
  {
   p=(int*)malloc(n*sizeof(int));

   printf("\nENTER THE NOS.\n");
   for(i=0;i<n;++i)
     scanf(" %d",p+i);
  printf("\nTHE GIVEN NOS. ARE\n");
   for(i=0;i<n;++i)
     printf(" %d",*(p+i));
  printf("\n\nHOW DO U WANT TO SORT THIS SERIES \n\t\t 1. IN ACENDING ORDER OR \n\t\t 2. IN DECENDING ORDER \n\t  Enter choice number:");
  scanf("%d",&choice);
  printf("\n\n");
  if(choice>2 || choice<1)
   {
     textcolor(RED+BLINK);
     cprintf("        UNEXPECTED CHOICE ENTERED!! SHOULD HAD ENTERED 1 OR 2 ");
     getch();
     exit();
   }

  sort(p,n,choice);

  for(i=0;i<n;++i)
    printf(" %d",*(p+i));
    }
    getch();
}
sort(int *p,int n,int c)
 {
   int i,j,*q;
   q=p;
   for(i=0;i<=n-1;++i)
    {
     p=q;
      for(j=0;j<=n-i-2;++j)
       {
	 if (c==1)
	   acending(p);
	 else
	   decending(p);
	++p;
       }
    }
   if(c==1)
     printf("\nTHE SORTED NOS. IN ACENDING ORDER ARE :\n\t");
   else
     printf("\nTHE SORTED NOS. IN DECENDING ORDER ARE :\n\t");
    return;
  }
acending(int *p)
 {
   int t;
   if(*p>*(p+1))
    {
     t=*p;
     *p=*(p+1);
     *(p+1)=t;
    }
  return;
 }
decending(int *p)
 {
   int t;
   if(*p<*(p+1))
    {
     t=*p;
     *p=*(p+1);
     *(p+1)=t;
    }
  return;
 }