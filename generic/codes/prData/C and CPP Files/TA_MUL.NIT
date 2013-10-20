#include<stdio.h>
enter_table(int a[3][4]);
display_table(int b[3][4]);
table_multiply(int a[3][4],int b[3][4]);
main()
 {
  int a[3][4],b[3][4];
  clrscr();
  printf("\t\tPROGRAM FOR MULTIPLYING CORR. ELEMENTS OF TWO TABLES");

  printf("\n\n\tENTER THE ELEMENTS OF THE FIRST TABLE");
  enter_table(a);

  printf("\n\tENTER THE ELEMENTS OF THE SECOND TABLE");
  enter_table(b);

  printf("\n\tTHE ELEMENTS OF THE FIRST TABLE");
  display_table(a);

  printf("\n\tTHE ELEMENTS OF THE SECOND TABLE");
  display_table(b);

  table_multiply(a,b);

  printf("\n\tTHE ELEMENTS OF THE TABLE AFTER THE MULTIPLICATION");
  display_table(a);
  getch();
 }

enter_table(int a[3][4])
 {
  int i,j;
   for(i=0;i<3;++i)
     for(j=0;j<4;++j)
      scanf("%d",&a[i][j]);
   return;
  }

display_table(int b[3][4])
 {
  int i,j;
  for(i=0;i<3;++i)
   {
     printf("\n\t\t");
     for(j=0;j<4;++j)
      printf(" %d",b[i][j]);
   }
   return;
 }

table_multiply(int a[3][4],int b[3][4])
{
 int i,j;
 for(i=0;i<3;++i)
   for(j=0;j<4;++j)
     a[i][j]*=b[i][j];
  return;
 }