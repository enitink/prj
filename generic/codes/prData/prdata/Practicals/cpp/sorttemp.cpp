#include<iostream>
#include<iomanip>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: setw;

template <class T>

void sort(T *p, int n)
{
    T *q,t;
        
    q=p;
    
    for(int i=0;i<n;++i)
    {
      p=q;
      for(int j=0;j<n-i-1;++j)
      {
	  if(*p<*(p+1))
	  {
	      t=*p;
	      *p=*(p+1);
	      *(p+1)=t;
	  }
	  ++p;
      }
    }
}

int main()
{
	int n, *p, i;
	float *fp;
	
	cout << "\n\n\t\tPROGRAM FOR SORTING GIVEN NUMBERS IN DECENDING ORDER";
	cout << "\n\nENTER THE NUMBER OF TERMS U WANT TO INPUT";
	cin >> n;
	
	if(n<=1)
		cout << "\n\nSORTING IS NOT POSSIBLE IN THIS CASE";
	else
	{
		p = (int *) malloc(n * sizeof(int));
		fp = (float *) malloc(n * sizeof(float));
		  
		cout << "\n\nENTER THE NOS.";
		for(i = 0; i < n; ++i)
		{
			cout << "\nINT : " << i + 1 << " : ";
			cin >> p[i];
			cout << "FLOAT : " << i + 1 << " : ";
			cin >> fp[i];	
		}	
		
		cout << "\n\nTHE GIVEN NOS. ARE";
		for(i = 0; i < n; ++i)
		{
			cout << "\n" << i + 1 <<  " : " << " INT : " << p[i];
			cout << "\n" << i + 1 <<  " : " << " FLOAT : " << fp[i];
		}
		
		sort(p,n);
		sort(fp,n);
		
		cout << "\n\nTHE SORTED NOS. ARE" ;
		for(i = 0; i<n ; ++i)
		{
			cout << "\n" << i + 1 <<  " : " << " INT : " << setw(3) << p[i];
			cout <<  "  :  FLOAT : " << fp[i];
		}
	}
	
	cout << endl;	
	return 0;
}
