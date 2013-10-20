#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<new>

void sort(int *p,int n)
{
	int i=1,j,temp;
    	while(i==1)
	{
		i=0;
		for(j=0;j<n-1;++j)
		{
			if(*p>*(p+(j+1)))
			{
				temp=*p;
				*p=*(p+(j+1));
				*(p+(j+1))=temp;
                		i=1;
			}
		}
	}
   return;
}  

int lcm(int no,int *array)
{
	int rem = 0, rem1 = 0;
	int i, j, k = 0;
	int factor[20];
	int result = 1;
	int zero = 0, temp = 0;
	int maxno = array[0];

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
	int *array;
	int no;
	int i,j;
	int result,temp;

	cout << "\n\n\tEnter no of terms in the array : ";
	cin >> no;

	array = new int[no];

	cout << "\n\n\tEnter the elements of the array : ";
	for(i=0;i<no;++i)
	   cin >> array[i];
        
	cout << "\n\n\tThe entered array is as follows : ";
 	for(i=0;i<no;++i)
	   cout << "  " <<  array[i];

	sort(array, no);
	   
        if(array[no-1]==0)
	   cout << "\n\n\tThe LCM of the entered array is 0 ";
	else
		result=lcm(no,array);

	cout << "\n\n\n\tThe LCM of the entered array is : "  << result;

	cout << endl;
	return 0;
}
