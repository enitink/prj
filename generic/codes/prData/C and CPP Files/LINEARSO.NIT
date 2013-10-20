/*this program has been written by Nitin Kumar*/
#include<stdio.h>
#include<graphics.h>
main()
 {
  int p[100],t,n,i,j,k;
  printf("\n Enter The size of the array");
  scanf("%d",&n);
  printf("\n Enter the array");
  p[0]=0;

   for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
   for(j=1;j<n;j++)
    {
     i=j;
     while(p[i]>p[i+1])
      {
	t=p[i+1];
	p[i+1]=p[i];
	p[i]=t;
	--i;
      }
      printf("\n step : %d : result :",j);
      for(k=1;k<=n;++k)
	 printf(" %d",p[k]);
     }
   printf("\nThe result");
   for(i=1;i<=n;i++)
    printf(" %d",p[i]);
 getch();
}



