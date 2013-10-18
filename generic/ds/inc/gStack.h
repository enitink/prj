#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

n
template <class T>
class Stack{
private :
	T * NextAddress;
	int top;		
public :
	Stack()	{
		NextAddress = NULL;
		top = -1;
	}	
	Stack(int Size)	{
		top = -1;
		NextAddress = new T[Size + 3];
	}	
	void Push_Data(T  Address) {
		++top;
		NextAddress[top] = Address;
	}	
	T Pop_Data() {
		return (top == -1) ? NULL : NextAddress[top--];
	}	
	int Ret_Top() {
		return top;
	}
};
