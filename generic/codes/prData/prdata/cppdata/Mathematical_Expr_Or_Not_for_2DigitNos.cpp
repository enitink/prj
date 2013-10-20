#include<iostream>
#include<cstring>
#include<iomanip>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: setw;

template < class T >
void Initialize(T *Stack, int Capacity, T Val)
{
	for(int i = 0; i < Capacity; ++i)
		Stack[i] = Val;
}

template < class T >
void Display(T *Stack,int Capacity)
{
	for(int i = 0; i <= Capacity; ++i)
		cout << Stack[i] << ":"; 	
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
}

template < class T >
T Pop_out_of_Stack(T *Stack, int *Top)
{
	if(*Top < 0)
	{
		cout << endl << "Under Flow" << endl;
		exit(0);
	}
	else
	{
		(*Top)--;
		return Stack[*Top + 1];
	}
}

char Operators(char Character)
{
	switch (Character)
	{
		case '+' :
			return '+';
		case '-' :
			return '-';
		case '*' :
			return '*';
		case '/' :
			return '/';
		case '(' : 
			return '(';
		case ')' :
			return ')';
		default :
			return '`';
	}
}

char Operands(char Character)
{
	switch (Character)
	{
		case '0' :
			return '0';
		case '1' :
			return '1';
		case '2' :
			return '2';
		case '3' :
			return '3';
		case '4' : 
			return '4';
		case '5' :
			return '5';
		case '6' :
			return '6';
		case '7' :
			return '7';
		case '8' :
			return '8';
		case '9' :
			return '9';
		default :
			return '`';
	}
}

int String_Con_Int(const char c)
{
	return (c >= '0' || c <= '9') ? c - '0' : -1;
}

bool Check_Mathematical_Expr_Or_Not(char *String)
{
	int  i = 0;       				//Counter for String Subscript.  
	int  OpTop = -1;  				//Counter for Operand Stack.
	int  OtTop = -1;  				//Counter for Operator Stack.
	//int  Counter = 0; 				//For keeping track of last scanned entry whether it was a Operator or a Operand 0 for Operator and 1 for Operands.
	int  Sign = 1;    				//For Keeping track of Sign.
	int  S_Bracket = 0;				//Counter for numbers of brackets.
	int  Capacity = strlen(String);			//For memory allocation for stacks.
	int  Value;					//For Stack Entry after Calculations	
	
	int  *Operands_Stack = new int(Capacity);	//Stack for Operands involved in the expressions.
	Initialize(Operands_Stack, Capacity, 0);
	char *Operators_Stack = new char(Capacity);	//Stack for Operators involved in the expressions.
	Initialize(Operators_Stack, Capacity, ' ');
	
	while(1)
	{
		if(Operators(String[i]) == '/' || Operators(String[i]) == '*')
			return false;
		else
			if(Operators(String[i]) == '+')
				++i; 
			if(Operators(String[i]) == '-')
			{
				++i;
				Sign = Sign * (-1);
			}
			else 
				break;
	}
	
	while(String[i] != '\0')
	{
		if(String[i] == Operators(String[i]))
		{
			if(String[i] == '(')
				++S_Bracket;	
			
			if(String[i] == ')' && S_Bracket >= 1)
			{
				while(true)
				{
					if(Pop_out_of_Stack(Operators_Stack, &OtTop) == '(')
					{
						--S_Bracket;
						break;
					}
					Pop_out_of_Stack(Operands_Stack, &OpTop);
				}
			}
			else
				Push_in_Stack(Operators_Stack, String[i], Capacity, &OtTop);
			
			if(OpTop >= 1 && S_Bracket == 0) 
			{
				Pop_out_of_Stack(Operands_Stack, &OpTop);
				Pop_out_of_Stack(Operators_Stack, &OtTop);
			}
			
			//Counter = 0;
		}
		else 
		{
			if(String[i] == Operands(String[i]))
			{
				//if (Counter == 1)
				//{
				//	Value = (Operands_Stack[OpTop] * 10) +  String_Con_Int(String[i]);
				//	--OpTop;
				//}
				//else
				//	Value = String_Con_Int(String[i]); 
				Value = 0;
				while(String[i] == Operands(String[i]))
				{
					Value = (Value * 10) + String_Con_Int(String[i]);
					++i;
				}
				--i;

				Value = Value * Sign;

				Push_in_Stack(Operands_Stack, Value, Capacity, &OpTop);
				
				//if(OpTop >= 1 && S_Bracket == 0 && Counter == 1) 
				if(OpTop >= 1 && S_Bracket == 0) 
				{
					Pop_out_of_Stack(Operands_Stack, &OpTop);
					Pop_out_of_Stack(Operators_Stack, &OtTop);
					//Counter = 0;
				}
				else
				{
					//Counter = 1;
					Sign = 1;
				}
			}
			else
				return false;
		}
		cout << endl << i <<  setw(20) << String[i];
		cout << setw(15) << " ";
		Display(Operators_Stack, OtTop);
		cout << setw(30) << " ";
		Display(Operands_Stack, OpTop);
		++i;
	} 
	
	cout << endl << "OtTop = " << OtTop << "\tOpTop = " << OpTop;
	return (OtTop == -1 && OpTop == 0) ? true : false;
}

int main()
{
	char *String;
	int Len;
	
	cout << endl << "Enter Length of the expression : ";
	cin >> Len;
	
	String = new char[Len];
	
	cout << endl << "Enter the String : ";
	cin >> String;
	
	cout << endl << "Entered String : " << String << ":";
	
	cout << endl;
	if(Check_Mathematical_Expr_Or_Not(String))
		cout << endl << "Given String is a Valid Expression";
	else
		cout << endl << "Given String is not a Valid Expression";
	
	cout << endl;
	
	return 0;
}