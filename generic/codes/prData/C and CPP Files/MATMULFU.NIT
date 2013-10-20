#include<stdio.h>
#include<conio.h>
#include<alloc.h>

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

int * multiply(int *a,int *b,int *c,int row,int col)

void main()
 {
  int a[5][5],b[5][5],c[5][5],row,col;
  clrscr();

  printf ("\nEnter Row and Column of Matrix A: \n");
  scanf(" %d%d",&row,&col);

  printf("\nEnter Matrix A:");
  input(a,row,col);

  printf("\nEnter Matrix b:");
  input(b,row,col);

  printf("\nThe Matrix A is as follows\n");
  display(a,row,col);

  printf ("\nThe Matrix B is as follows\n");
  display(b,row,col);

  getch();
}
