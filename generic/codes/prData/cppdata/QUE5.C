/* Program for printing a Tree of the given format */

#include<stdio.h>

int main()
{
	int i,j,count=1,check=1;
	int space=5;
	clrscr();

	for(i = 1 ; i <= 5 ; ++i)
	{
            printf("\n\n");

	    for(count = 1 ; count <= 3; ++count)
	    {
	       for(j = 1 ; j <= space-i ; ++j)
		 printf("  ");
	       for(j = 1 ; j <= i ; ++j)
		 printf(" %d",j);
	       for(j = i-1 ; j >= 1 ; --j)
		 printf(" %d",j);

	       if(check==1)
	       {
		  space=15-i;
		  check=0;
	       }
	     }

	     check=1;
	     space=5;

	 }

	 getch();
	 return 0;
}
