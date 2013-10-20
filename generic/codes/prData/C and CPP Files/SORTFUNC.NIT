#include<stdio.h>
sort();
int *p,n;
main()
 {
  int i,j,t;
  clrscr();
  printf("\n\n\t\tPROGRAM FOR SORTING GIVEN NUMBERS IN DECENDING ORDER");
  printf("\n\nENTER THE NUMBER OF TERMS U WANT TO INPUT");
  scanf("%d",&n);
  if(n<=1)
    printf("\n\nSORTING IS NOT POSSIBLE IN THIS CASE");
  else
  {
   p=(int*)malloc(n*sizeof(int));

   printf("\n\nENTER THE NOS.");
    for(i=0;i<n;++i)
      scanf(" %d",p+i);
   printf("\n\nTHE GIVEN NOS. ARE");
    for(i=0;i<n;++i)
     printf(" %d",*(p+i));
   sort();
   printf("\n\nTHE SORTED NOS. ARE");
     for(i=0;i<n;++i)
       printf(" %d",*(p+i));
   getch();
 }
 }

 sort()
  {
    int *q;
    int i,j,t;
    q=p;
    for(i=0;i<=n-1;++i)
     {
      p=q;
      for(j=0;j<=n-i-2;++j)
	{
	  if(*p<*(p+1))
	    {
	      t=*p;
	      *p=*(p+1);
	      *(p+1)=t;
	    }
	    ++p;
	}
      }
  }
