#include<iostream>
#include<cstring>

using std :: cin;
using std :: cout;
using std :: endl;

template < class T >
void Display(T *Stack,int Capacity, char * String)
{
	cout << endl << endl;
	cout << "Operation : " << String;
	for(int i = 0; i <= Capacity; ++i)
		cout << Stack[i] << " : "; 
}

template < class T >
void Push_in_Stack( T *Stack, T Value, int Capacity, int *Top)
{
	if(*Top + 1 == Capacity)
	{
		cout << endl << "Stack Full";
	}
	else
	{
		(*Top)++;
		Stack[ *Top ] = Value;
	}
	Display(Stack, *Top, "Pushing in Stack");
}

template < class T >
T Pop_out_of_Stack(T *Stack, int *Top)
{
	Display(Stack, *Top, "Poping out of Stack");
	if(*Top < 0)
	{
		cout << endl << "Under Flow";
	}
	else
	{
		(*Top)--;
		return Stack[*Top + 1];
	}
}

int main()
{
	int len;
	int Value;
	int Top = -1;
	
	cout << endl << "Enter Stack Size : ";
	cin >> len;
	
	int *Stack = new int[len];
	
	cout << endl << "Enter Data : ";
	for(int i = 0; i < len; ++i)
	{
		cin >> Value;
		Push_in_Stack(Stack, Value, len, &Top);
	}
	
	while(Pop_out_of_Stack(Stack, &Top) != 0);
	
	cout << endl << "Value of Top  = "  << Top;
	cout << endl;
	return 0;
}