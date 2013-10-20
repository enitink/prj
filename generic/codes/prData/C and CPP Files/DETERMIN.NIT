#include<stdio.h>
main()
 {
  int i,j,k,a[10][10],a1[10][10],r,c;
  float sum=0,psum=0,partial=1,nsum=0;
  printf("\nENTER THE ORDER(row * col ) OF THE DETERMINANT");
  scanf("%d %d",&r,&c);
  printf("\nenter the values of determinant (row * col)");
   for(i=0;i<r;++i)
     for(j=0;j<c;++j)
       scanf("%d",&a[i][j]);
   if(r==c)
    {
    if(r<3)
     sum=a[0][0]*a[1][1]-a[1][0]*a[0][1];
    else
     {
      for(i=0;i<r;++i)
       for(j=0;j<r;++j)
	a1[i][j]=a[i][j];
      for(i=0;i<r;++i)
       for(j=r;j<(2*r)-1;++j)
	a1[i][j]=a1[i][j-r];
      for(i=0;i<r;++i)
       {
	partial=1;
	for(j=0;j<r;++j)
	 partial*=a1[j][j+i];
	psum+=partial;
       }
      for(i=r-1;i<(2*r-1);++i)
       {
	partial=1;
	for(j=0;j<r;++j)
	 partial*=a1[j][i-j];
	nsum+=partial;
       }
     sum=psum-nsum;
     }
   }
  else
   printf("\ndeterminant is not posible");
  printf("\nmatrix entered (a=)");
  for(i=0;i<r;++i)
    for(j=0;j<r;++j)
      printf("%d",&a[i][j]);
  printf("\nmatrix calculated (a=)");
  for(i=0;i<r;++i)
    for(j=0;j<(2*r-1);++j)
      printf("%d",&a1[i][j]);
  printf("value of r=%d c=%d sum=%f    psum=%f    nsum=%f  partial=%f",r,c,sum,psum,nsum,partial);
getch();
}