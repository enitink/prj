// Write a program, using the concept of recursion, to find the maximum and minimum
// and maximum from a given set of numbers.

#include<stdio.h>
#include<stdlib.h>
#include<alloc.h>
#include<conio.h>




int main()
{
	int noofelements,*elements;
   int i;

   printf("\nEnter the no. of terms of the elements(numbers)");
   scanf("%d",&noofelements);

   elements=(int *) malloc(sizeof(int) * noofelements);

   printf("\nEnter all the elements(numbers)");
   for(i=0 ; i< noofelements ; ++i)
   	scanf("%d",elements+i);

   printf("\n the unsorted elements");
   for(i=0; i < noofelements ; ++i)
       printf("%d",*(elements+i));

   sort(noofelements,elements);

   //printf("\nThe largest of the given nos. is   : %d",*(elements+noofelements-1));
   //printf("\nThe smallest of the given nos. is  : %d",*(elements+0));

   printf("\n the sorted elements");
   for(i=0; i < noofelements ; ++i)
       printf("%d",*(elements+i));

   getch();

    return 0;
}

