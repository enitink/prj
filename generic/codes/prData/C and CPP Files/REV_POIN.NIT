#include<stdio.h>
main()
{
 int *p,i,n;
 printf("\n\t\tPROGRAM FOR REVERSING AN ARRAY USING POINTER");
 printf("\n\tENTER THE NO. OF ELEMENTS : ");
 scanf("%d",&n);
 p=(int*) malloc(n*sizeof(int));
 printf("\nENTER THE ARRAY OF NUMBERS : ");
 for(i=0;i<n;++i)
  scanf("%d",(p+i));
 printf("\nTHE GIVEN ARRAY IS : ");
 for(i=0;i<n;++i)
  printf(" %d",*(p+i));
 printf("\nTHE REVERSED ARRAY : ");
 for(i=n-1;i>=0;--i)
  printf(" %d",*(p+i));
 getch();
}