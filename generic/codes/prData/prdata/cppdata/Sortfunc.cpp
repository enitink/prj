#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

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
               
void main()
{ 
	int *ptr,noofelements;
	
	cout << "Enter no. of Terms" << endl;
    cin >> noofelements;

	ptr=(int *) malloc(sizeof(int)*noofelements);

	cout << endl << "Enter The Terms" << endl;
	for(int i=0;i<noofelements;++i)
	   cin >> *(ptr+i);
	
	sort(ptr,noofelements);   

	cout << "The Sorted Nos. Are" << endl;
	for(i=0;i<noofelements;++i)
		cout << " " <<*(ptr+i);
    
}