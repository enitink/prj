/*WRITE A PROGRAM TO FIND THE L.C.M OF N INTEGERS WHERE N IS
GREATER THAN TWO*/
#include<stdio.h>
#include<stdlib.h>

int lcm(int no,int *array)
{
	int rem=0,rem1=0;
	int i,j,k=0;
	int factor[20];
	int result=1;
	int zero=0,temp=0;
	int maxno=*(array+0);

	for(i=0;i<20;++i)
	    factor[i]=1;

	while(rem != 1)
	{
	  for(i=2 ; i<=maxno ; ++i)
	  {
	     while(rem1 != 1)
	     {
		temp=0;

		for(j=0 ;j<no ;++j)
		{
		  if(*(array+j)%i==0)
		  {
		     if(temp == 0)
		     {
			factor[k]=i;
			temp = 1;
			++k;
		     }
		     *(array+j) /= i;
		  }
		}

		rem1=1;

		for(j=0;j<no;++j)
		{
		  if(*(array+j)%i != 0)
		     rem1 *= 1;
		  else
		     rem1 *= zero;
		}
	     }

	    rem1=0;
	  }

	  rem=1;

	  for(i=0;i<no;++i)
	  {
	     if(*(array+i)==1)
		rem *= 1;
	     else
		rem *= zero;
	  }
	}

	for(i=0;i<k;++i)
	    result *= factor[i];

	return result;

}


int main()
{
	int *array,*ptr;
	int no;
	int i,j;
	int result,temp;

	clrscr();

	printf("\n\n\tEnter no of terms in the array : ");
	scanf(" %d",&no);

	if(no<=2)
	{
	   printf("\n\n\tInvalid no. of terms, enter greater than 2");
	   getch();
	   exit(0);
	}

	array=(int *) malloc(sizeof(int)*no);

	printf("\n\n\tEnter the elements of the array : ");
	for(i=0;i<no;++i)
	   scanf(" %d",array+i);


        ptr=array;
        for(i=0;i<no;++i)
        {  array=ptr;
	   for(j=0;j<no-i-1;++j)
	   {
	     if(*array<*(array+1))
	     {
	       temp=*array;
	       *array=*(array+1);
	       *(array+1)=temp;
	     }
	     ++array;
	   }
        }

	array=ptr;

	printf("\n\n\tThe entered array is as follows : ");
 	for(i=0;i<no;++i)
	   printf(" %d ",*(array+i));

        if(*(array+no-1)==0)
	{
	   printf("\n\n\tThe LCM of the entered array is 0 ");
	   getch();
	   exit(0);
	}

	result=lcm(no,array);

	printf("\n\n\n\tThe LCM of the entered array is %d",result);

	getch();

	return 0;
}
