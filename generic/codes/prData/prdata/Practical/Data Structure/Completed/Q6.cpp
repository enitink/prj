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
	for(int i = 0; i <= Capacity; ++i)
		Stack[i] = Val;
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

int ValOfOt(char Character)
{
	switch (Character)
	{
		case '+' :
			return 1;
		case '-' :
			return 2;
		case '*' :
			return 5;
		case '/' :
			return 6;
	}
}

int String_Con_Int(const char c)
{
	return (c >= '0' || c <= '9') ? c - '0' : -1;
}

int Infix_To_Postfix(char * Infix_Expr, char * Postfix_Expr)
{
	int Infix_Expr_Counter = 0;
	int Value = 0;
	int S_Bracket = 0;
	int Counter = 1;
	int Capacity = strlen(Infix_Expr);
	
	char Scanned_Char = ' ';
		
	char * Operator_Stack;
	int Ot_Stack_Top = -1;
	Operator_Stack = new char[Capacity];
	Initialize(Operator_Stack, Capacity, '\0');
	
	int Postfix_Expr_Counter = -1;
	
	while(Infix_Expr[Infix_Expr_Counter] != '\0')
	{
		if(Infix_Expr[Infix_Expr_Counter] == Operators(Infix_Expr[Infix_Expr_Counter]))
		{
			if(Infix_Expr[Infix_Expr_Counter] == '+' && Counter == 1)
			{
				++Infix_Expr_Counter;
				continue;
			}
			if(Infix_Expr[Infix_Expr_Counter] == '-' && Counter == 1)
			{
				++Postfix_Expr_Counter;
				Postfix_Expr[Postfix_Expr_Counter] = '-';
			}
			else
			{
				if(Infix_Expr[Infix_Expr_Counter] == ')' && S_Bracket >= 1)
				{
					while(true)
					{
						
						Scanned_Char = Pop_out_of_Stack(Operator_Stack, &Ot_Stack_Top);
			
						if(Scanned_Char == '(')
						{
							--S_Bracket;
							break;
						}
			
						++Postfix_Expr_Counter;
						Postfix_Expr[Postfix_Expr_Counter] = Scanned_Char;
						++Postfix_Expr_Counter;
						Postfix_Expr[Postfix_Expr_Counter] = ',';
					}
				}
				else
				{
					if((Operator_Stack[Ot_Stack_Top] != '(') && ( ValOfOt(Infix_Expr[Infix_Expr_Counter]) < 7))
					{
						while((Ot_Stack_Top >= 0)
					  	&&  
					   	((ValOfOt(Infix_Expr[Infix_Expr_Counter]) <= ValOfOt(Operator_Stack[Ot_Stack_Top]))
					    	||
					    	(ValOfOt(Infix_Expr[Infix_Expr_Counter]) <= ValOfOt(Operator_Stack[Ot_Stack_Top]) + 1))
					  	&& 
					     	((Operator_Stack[Ot_Stack_Top]) !='('))
						{
							Scanned_Char = Pop_out_of_Stack(Operator_Stack, &Ot_Stack_Top);
							
							++Postfix_Expr_Counter;
							Postfix_Expr[Postfix_Expr_Counter] = Scanned_Char;
							++Postfix_Expr_Counter;
							Postfix_Expr[Postfix_Expr_Counter] = ',';
							
						}
						Push_in_Stack(Operator_Stack, Infix_Expr[Infix_Expr_Counter], Capacity, &Ot_Stack_Top);
					}
					else
						Push_in_Stack(Operator_Stack, Infix_Expr[Infix_Expr_Counter], Capacity, &Ot_Stack_Top);
					
				}
				
				if(Infix_Expr[Infix_Expr_Counter] == ')')
					Counter = 0;
				else
					Counter = 1;
				if(Infix_Expr[Infix_Expr_Counter] == '(')
					++S_Bracket;
			}
		}
		else 
		{
			if(Infix_Expr[Infix_Expr_Counter] == Operands(Infix_Expr[Infix_Expr_Counter]))
			{
				while(Infix_Expr[Infix_Expr_Counter] == Operands(Infix_Expr[Infix_Expr_Counter]))
				{
					++Postfix_Expr_Counter;
					Postfix_Expr[Postfix_Expr_Counter] = Infix_Expr[Infix_Expr_Counter];
					
					++Infix_Expr_Counter;
				}
				--Infix_Expr_Counter;
				++Postfix_Expr_Counter;
				Postfix_Expr[Postfix_Expr_Counter] = ',';
				Counter = 0;
			}
		}
		++Infix_Expr_Counter;
	}
	
	while(Ot_Stack_Top > -1)
	{
		Scanned_Char = Pop_out_of_Stack(Operator_Stack, &Ot_Stack_Top);
		
		++Postfix_Expr_Counter;
		Postfix_Expr[Postfix_Expr_Counter] = Scanned_Char;
		++Postfix_Expr_Counter;
		Postfix_Expr[Postfix_Expr_Counter] = ',';
	}
	
	return Postfix_Expr_Counter;
}

int main()
{
	int Capacity;
	int i, j;
	
	cout << endl << "Enter Length of the expression : ";
	cin >> Capacity;
	
	char *Infix_Expr;
	Infix_Expr = new char[Capacity];
	Initialize(Infix_Expr, Capacity, '\0');
	
	char * Postfix_Expr;
	Postfix_Expr = new char[Capacity];
	Initialize(Postfix_Expr, Capacity, '\0');
	
	cout << endl << "Enter the String : ";
	cin >> Infix_Expr;
	
	cout << endl << "Entered String : " << Infix_Expr << ":";

	cout << endl;
	int x = Infix_To_Postfix(Infix_Expr, Postfix_Expr);
	
	cout << endl << "PostFix expression will be = " << Postfix_Expr;
	cout << endl;

	return 0;
}