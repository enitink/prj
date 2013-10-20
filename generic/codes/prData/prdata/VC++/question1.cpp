/* Write a program, using the concept of recursion, to find the maximum and minimum
 and maximum from a given set of numbers.*/

#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>
#include<conio.h>

void sortsec(int n,int *array,int j)
{
   int temp;

   if(*(array+j) < *(array+j+1))
   {
      temp = *(array+j);
      *(array+j) = *(array+j+1);
      *(array+j+1) = temp;
   }

   ++j;

   if(j>=n)
     return;

   sortsec(n,array,j);
}

void sort(int n,int *array,int i)
{
  
   sortsec(n-i-1,array,0);

   ++i;

   if(i>=n)
     return;

   sort(n,array,i);
}


int main()
{
   int noofelements,*elements;
   int i;

   clrscr();
   printf("\nEnter the no. of terms of the elements(numbers)");
   scanf("%d",&noofelements);

   elements=(int *) malloc(sizeof(int) * noofelements);

   printf("\nEnter all the elements(numbers)");
   for(i=0 ; i< noofelements ; ++i)
   	scanf("%d",elements+i);

   sort(noofelements,elements,0);

   printf("\nThe largest of the given nos. is   : %d",*(elements+noofelements-1));
   printf("\nThe smallest of the given nos. is  : %d",*(elements+0));

   getch();
   return 0;
}

