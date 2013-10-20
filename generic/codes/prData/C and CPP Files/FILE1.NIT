#include<stdio.h>
main()
 {
  FILE *p1,*p2,*p3;
  int i,n,k[10],ke[10],ko[10],j=0,l=0,m;
  clrscr();
  p1=fopen("Data","w+");
  printf("\nenter the no. of data u want to enter");
  scanf("%d",&n);

  printf("\nenter the values of file data ");
  for(i=0;i<n;++i)
   {
    scanf("%d",&k[i]);
    fprintf(p1,"%d",k[i]);
   }

  p2=fopen("even","w+");
  p3=fopen("odd","w+");

  printf("\n the values of file data are as:-  ");
  for(i=0;i<n;++i)
  {
    fscanf(p1,"%d",&k[i]);
    printf("  %d",k[i]);
  }
  for(i=0;i<n;++i)
    {
     m=k[i]%2;
     if(m==0)
      {
	ke[j]=k[i];
	fprintf(p2,"%d",ke[j]);
	++j;
       }
     else
       {
	ko[l]=k[i];
	fprintf(p3,"%d",ko[l]);
	++l;
       }
    }

 printf("\n even file is as follows");
 for(i=0;i<j;++i)
  {
   fscanf(p2,"%d",&ke[i]);
   printf("  %d",ke[i]);
  }
 printf("\n odd file is as folows");
 for(i=0;i<l;++i)
  {
   fscanf(p3,"%d",&ko[i]);
   printf("  %d",ko[i]);
  }
 fclose(p1);
 fclose(p2);
 fclose(p3);
 getch();
}
