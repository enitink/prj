#include<iostream>
#include<cstring>

using std :: cin;
using std :: cout;
using std :: endl;

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
}

template < class T >
T Pop_out_of_Stack(T *Stack, int *Top)
{
	if(*Top < 0)
	{
		cout << endl << "Under Flow";
		return 0;
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
	int Ans = 1;
	int Value;
	int Top = -1;
	
	cout << endl << "Enter Stack Size : ";
	cin >> len;
	
	int *Stack = new int[len];
	
	while(Ans >= 1 &&  Ans <= 2)
	{
		cout << endl << "\t\tChoose from below options";
		cout << endl << endl << "\t1 : Insert an item into Stack(Push) ";
		cout << endl << "\t2 : Delete an item from Stack(Pop) ";
		cout << endl << "\t3 : Exit ";
		cout << endl << "\t\tEnter your Choice : ";
		cin >> Ans;
		
		switch(Ans)
		{
			case 1 :
			{
				cout << endl << endl << "\t Enter Data to PUSH : ";
				cin >> Value;
				Push_in_Stack(Stack, Value, len, &Top);
				break;
			}
			case 2 :
			{
				cout << endl << endl << "\tPopped Data = " << Pop_out_of_Stack(Stack, &Top);
				break;
			}
		}
		
	}
	
	cout << endl;
	return 0;
}