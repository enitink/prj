#include<stdio.h>
void enter_table(int a[10][10],int r,int c);
void display_table(int b[10][10],int r,int c);
int *table_multiply(int a[10][10],int b[10][10],int r,int c);
main()
 {
  int a[10][10],b[10][10],r=3,c=3,add[10][10];
  clrscr();
  printf("\t\tPROGRAM FOR MULTIPLYING CORR. ELEMENTS OF TWO TABLES");

  printf("\n\n\tENTER THE ELEMENTS OF THE FIRST TABLE");
  enter_table(a,r,c);

  printf("\n\tENTER THE ELEMENTS OF THE SECOND TABLE");
  enter_table(b,r,c);

  printf("\n\tTHE ELEMENTS OF THE FIRST TABLE");
  display_table(a,r,c);

  printf("\n\tTHE ELEMENTS OF THE SECOND TABLE");
  display_table(b,r,c);

  add=table_multiply(a,b,r,c);

  printf("\n\tTHE ELEMENTS OF THE TABLE AFTER THE MULTIPLICATION");
  display_table(add,r,c);
  getch();
 }

void enter_table(int a[10][10],int r,int c)
 {
  int i,j;
   for(i=0;i<r;++i)
     for(j=0;j<c;++j)
      scanf("%d",&a[i][j]);
   return;
  }

void display_table(int b[10][10],int r,int c)
 {
  int i,j;
  for(i=0;i<r;++i)
   {
     printf("\n\t\t");
     for(j=0;j<c;++j)
      printf(" %d",b[i][j]);
   }
   return;
 }

int *table_multiply(int a[10][10],int b[10][10],int r,int c)
{
 int i,j,c[10][10];
 for(i=0;i<r;++i)
   for(j=0;j<c;++j)
     c[i][j]=a[i][j]+b[i][j];
  return(&c);
 }