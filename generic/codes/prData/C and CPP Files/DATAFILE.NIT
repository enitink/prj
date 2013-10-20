#include<stdio.h>
main()
 {
  FILE *op;
  int numbers;
  int size,n,i;
  clrscr();
  op=fopen("d","r+");
  size=sizeof(numbers);
  printf("\nENTER NO. OF ELEMENTS :");
  scanf("%d",&n);
  printf("\nENTER THE NUMBERS :");
  for(i=0;i<n;++i)
   {
    scanf(" %d",&numbers);
    fwrite(&numbers,size,1,op);
   }
 rewind(op);
 while(fread(&numbers,size,1,op)==1)
   {
    if(numbers%2!=0)
     printf("%d ",numbers);
    }
 getch();
 }