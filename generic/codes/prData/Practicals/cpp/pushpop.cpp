#define MAX 5
#define CHECK 7 
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>
class Stack
{
private :
	int top;
	T stk[MAX];
public :
	Stack()
	{
		top = -1;
	}
	void Push(T data)
	{
		if(top + 1 != MAX)
			stk[++top] = data;
		else
			cout << endl << "Stack is Full" << endl;
	}
	T Pop()
	{
		T x = 0;
		if(top >= 0)
			x = stk[top--];
		else
			cout << endl << "No Data Found";
		return x;
	}
};

int main()
{
	Stack <int> st;
	Stack <float> fst;
	int tst;
	float ftst;
	
	for(int i = 0; i < CHECK; ++i)
	{
		cout << endl << "Enter data no. : " << i + 1 << " : of INT type    : ";
		cin >> tst;
		st.Push(tst); 
		cout << endl << "Enter data no. : " << i + 1 << " :  of FLOAT type : ";
		cin >> ftst;
		fst.Push(ftst);
	}
	for(int i = 0; i < CHECK; ++i)
	{
		cout << endl << "Data no. : " << i + 1 << " : of INT type    : ";
		cout << st.Pop(); 
		cout << endl << "Data no. : " << i + 1 << " :  of FLOAT type : ";
		cout << fst.Pop();
	}
	
	cout << endl;	
	return 0;
}
