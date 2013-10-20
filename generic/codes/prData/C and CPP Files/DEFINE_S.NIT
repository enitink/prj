#include<stdio.h>
#define SORT  for(i=0;i<=n-1;++i)\
	       { \
		p=q;\
		for(j=0;j<=n-i-2;++j)\
		 {\
		  if(*p>*(p+1))\
		   {\
		    t=*p;\
		    *p=*(p+1);\
		    *(p+1)=t;\
		   }\
		 ++p;\
		 }\
	       }
main()
 {
  int n,i,*p,*q,j,t;
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
    printf("\n\nTHE SORTED SERIES IS AS FOLLOWS \n\t\t IN ACENDING ORDER OR:");
    q=p;
    SORT;
    for(i=0;i<n;++i)
       printf(" %d",*(p+i));
  }
    getch();
}
