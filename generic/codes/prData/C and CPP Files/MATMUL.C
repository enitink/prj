/* Program for  multiplying two matrices with the help of pointers */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void input(int *a,int r,int c)
 {
   int i,j;
   for(i=0;i<r;++i)
    {
     for(j=0;j<c;++j)
	scanf("%d",(a+i+j));
   }
  return;
 }

void display(int *a,int r,int c)
 {
    int i,j;
    for(i=0;i<r;++i)
     {
      printf("\n");
       for(j=0;j<c;++j)
	 printf(" %d",*(a+i+j));
     }
   return;
 }

void multiplication(int *a,int *b,int *c,int row,int col1,int col)
{
    int i,j,k;

    for(i=0; i<row; ++i)
    {
       for(j=0 ; j<col1 ; ++j)
       {
	   *(c+i+j)=0;
	   for(k=0 ; k<col ;++k)
	   {
	     *(c+i+j) = *(c+i+j) + *(a+i+k) * *(b+k+i);
	   }
       }
    }
}

int main()
 {
  int a[5][5],b[5][5],c[5][5],row,col,row1,col1;
  clrscr();

  printf ("\nEnter Row and Column of Matrix A : \n");
  scanf(" %d%d",&row,&col);

  printf ("\nEnter Row and Column of Matrix B : \n");
  scanf(" %d%d",&row1,&col1);

  if(col != row1)
	exit(0);

  printf("\nEnter Matrix A :");
  input(&a[0][0],row,col);

  printf("\nEnter Matrix b :");
  input(&b[0][0],row1,col1);

  printf("\nThe Matrix A is as follows :\n");
  display(&a[0][0],row,col);

  printf("\nThe Matrix B is as follows :\n");
  display(&b[0][0],row1,col1);

  multiplication(&a[0][0],&b[0][0],&c[0][0],row,col1,col);

  printf("\nThe Matrix A*B is as follows :\n");
  display(&c[0][0],row,col1);

  getch();

  return 0;
}
