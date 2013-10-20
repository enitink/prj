 
#include<iostream>
#include<cstring>
#include<iomanip>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: setw;

template < class T >
void Display(T *Stack,int Capacity)
{
	for(int i = 0; i <= Capacity; ++i)
		cout << Stack[i] << ":"; 	
}

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
T Pop_Out_Of_Stack(T *Stack, int *Top)
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

double Calculate_Postfix(char * Entered_Postfix_Expr)
{
	int Sign = 1;
	double Value = 0.0;
	
	int Capacity = strlen(Entered_Postfix_Expr);
	double * Operand_Stack;
	int Op_Stack_Top = -1;
	Operand_Stack = new double[Capacity];
	Initialize(Operand_Stack, Capacity, 0.0);
	
	for(int EnPostfix_Expr_Count = 0 ; EnPostfix_Expr_Count < strlen(Entered_Postfix_Expr); ++EnPostfix_Expr_Count)
	{
		if(Operators(Entered_Postfix_Expr[EnPostfix_Expr_Count]) == '-' &&
		   Operators(Entered_Postfix_Expr[EnPostfix_Expr_Count]) == Operands(Entered_Postfix_Expr[EnPostfix_Expr_Count]))
		{
			Sign = Sign * -1;
		}
		else
		{
			if(Entered_Postfix_Expr[EnPostfix_Expr_Count] == Operators(Entered_Postfix_Expr[EnPostfix_Expr_Count]))
			{
				switch(Entered_Postfix_Expr[EnPostfix_Expr_Count])
				{
					case '+' :
					{
						Value = 0;
						
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						Value += Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						
						Push_in_Stack(Operand_Stack, Value, Capacity, &Op_Stack_Top);
						break;
					}
					case '-' :
					{
						Value = 0;
						
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top) - Value;
						
						Push_in_Stack( Operand_Stack, Value , Capacity, &Op_Stack_Top);
						break;
					}
					case '*' :
					{
						Value = 0;
						
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						Value *= Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						
						Push_in_Stack( Operand_Stack, Value , Capacity, &Op_Stack_Top);
						break;
					}
					case '/' :
					{
						Value = 0;
						
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top);
						Value = Pop_Out_Of_Stack(Operand_Stack, &Op_Stack_Top) / Value;
					
						Push_in_Stack( Operand_Stack, Value , Capacity, &Op_Stack_Top);
						break;
					}
				}
			}
			else
			{
				if(Entered_Postfix_Expr[EnPostfix_Expr_Count] == Operands(Entered_Postfix_Expr[EnPostfix_Expr_Count]))
				{
					Value = 0.0;
			
					while(Entered_Postfix_Expr[EnPostfix_Expr_Count] == Operands(Entered_Postfix_Expr[EnPostfix_Expr_Count]))
					{
						Value = (Value * 10) + String_Con_Int(Entered_Postfix_Expr[EnPostfix_Expr_Count]);
						++EnPostfix_Expr_Count;
					}
					--EnPostfix_Expr_Count;
			
					Value =  Value * Sign;
			
					Sign = 1;
					Push_in_Stack( Operand_Stack, Value, Capacity, &Op_Stack_Top);
				}
				else
				{
					if(Entered_Postfix_Expr[EnPostfix_Expr_Count] == ',')
					{
						Sign = 1;
					}
				}
			}
			Sign = 1;
		}
	}
	
	return Operand_Stack[Op_Stack_Top];
} 

int main()
{
	int Capacity;
	
	cout << endl << "/*** Use , as delimiter between two operator and operand in the Postfix Expr ***\\";
	cout << endl << "Enter Length of the expression : ";
	cin >> Capacity;
		
	char * Entered_Postfix_Expr;
	Entered_Postfix_Expr = new char[Capacity];
	Initialize(Entered_Postfix_Expr , Capacity, '\0');
	
	cout << endl << "Enter the String : ";
	cin >> Entered_Postfix_Expr;
	
	cout << endl << "Entered String : " << Entered_Postfix_Expr << ":";

	cout << endl;
	
	double Result = Calculate_Postfix(Entered_Postfix_Expr);
	
	cout << endl << Entered_Postfix_Expr << " = "  << Result;
	
	cout << endl;

	return 0;
}