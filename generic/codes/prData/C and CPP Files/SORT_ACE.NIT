#include<stdio.h>
main()
 {
  int n,i,j,t,*p,*q;
  clrscr();
  printf("\nPROGRAM FOR SORTING GIVEN NUMBERS IN ACENDING ORDER");
  printf("\nENTER THE NUMBER OF TERMS U WANT TO INPUT");
  scanf("%d",&n);
  if(n<=1)
    printf("\nSORTING IS NOT POSSIBLE IN THIS CASE");
  else
  {
   p=(int*)malloc(n*sizeof(int));

   printf("\nENTER THE NOS.");
   for(i=0;i<n;++i)
     scanf(" %d",p+i);
  printf("\nTHE GIVEN NOS. ARE");
   for(i=0;i<n;++i)
     printf(" %d",*(p+i));
    q=p;
   for(i=0;i<=n-1;++i)
    {  p=q;
      for(j=0;j<=n-i-2;++j)
	{
	  if(*p>*(p+1))
	    {
	      t=*p;
	      *p=*(p+1);
	      *(p+1)=t;
	     }
	    ++p;
	    }
      }
    printf("\nTHE SORTED NOS. ARE");
     for(i=0;i<n;++i)
       printf(" %d",*(p+i));
    }
    getch();
}