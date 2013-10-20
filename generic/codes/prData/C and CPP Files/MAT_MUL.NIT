/*********PROGRAM FOR MULTIPLICATION OF TWO MATRICES**********/
/********** AUTHOR OF THIS PROGRAM IS NITIN KUMAR ************/
#include<stdio.H>

main()
{
  int m,n,q,p,i,j,k,a[8][8],b[8][8],c[8][8];

  clrscr();

  printf("\n\t\t  PROGRAM FOR MULTIPLICATION OF TWO MATRICES");
  printf("\n\n\t  ENTER THE VALUE OF ROW(m) &COLOUMN(N) OF THE MATRIX A");
  scanf("%d%d",&m,&n);
  printf("\n\t  ENTER THE VALUE OF ROW(q) & COLOUMNM(p) OF THE MATRIX B");
  scanf("%d%d",&q,&p);

  if(n!=q)
    printf("\n\t\tTHE MATRIX A*B DOES NOT EXISTS");
  else
    {
      printf("\nEnter matrix a:-");
      input_matrix(a,m,n);

      printf("\nEnter matrix b:");
      input_matrix(b,q,p);

      printf("\n\t\tTHE GIVEN MATRIX (A) IS:-");
      display_matrix(a,m,n);

      printf("\n\t\tTHE GIVEN MATRIX (B) IS:-");
      display_matrix(b,q,p);

      matrix_mul(a,b,c,m,n,p);

      printf("\n\t\tTHE PRODUCT OF THE TWO GIVEN MATRIX(A*B) IS:-");
      display_matrix(c,m,p);
     }
   getch();
 }

input_matrix(int a[8][8],int q,int p)
 {
   int i,j;
   for(i=0;i<q;++i)
    {
     for(j=0;j<p;++j)
      {
	scanf("%d",&a[i][j]);
      }
     }
   return;
 }

display_matrix(int a[8][8],int q,int p)
 {
  int i,j;
  for(i=0;i<q;++i)
   {
     printf("\n\t\t");
     for(j=0;j<p;++j)
      {
	printf(" %5d",a[i][j]);
      }
   }
  return;
 }

matrix_mul(int a[8][8],int b[8][8],int c[8][8],int m,int n,int p)
 {
  int i,j,k;
    for(i=0;i<m;++i)
     {
       for(j=0;j<p;++j)
	{
	  c[i][j]=0;
	  for(k=0;k<n;++k)
	   {
	     c[i][j]=c[i][j]+a[i][k]*b[k][i];
	   }
	}
      }
   return;
 }