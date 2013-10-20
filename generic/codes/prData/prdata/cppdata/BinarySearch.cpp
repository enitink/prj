#include<iostream>
#include<iomanip>

using namespace std;

void Sort(int *p,int n)
{
	int temp;
    	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = 0; j < n - 1 - i; ++j)
		{
			if(*(p + j) > *(p+(j+1)))
			{
				temp = *(p + j);
				*(p + j) = *(p+(j+1));
				*(p+(j+1)) = temp;                			
			}
		}
	}
   return;
}  
  
int main()
{
	int *Array, NoofElements,i;
	cout << endl << "Enter No of Elements for The Array : ";
	cin  >> NoofElements;

	Array = new int[NoofElements];
	
	cout << "Enter The Elements of The Array" << endl;
	for(i = 0; i < NoofElements; ++i)
	{
		cout << "Enter Element No. : " << i + 1 << " : ";
		cin >> Array[i];
	}

	cout << "Entered Elements Are : ";
	for(i = 0; i < NoofElements; ++i)
		cout << setw(6) << Array[i];
	
	Sort(Array, NoofElements);

	cout << endl << "Sorted Elements Are : ";
	for(i = 0; i < NoofElements; ++i)
		cout << setw(6) << Array[i];

	cout << endl;
	return 0;
}
	
