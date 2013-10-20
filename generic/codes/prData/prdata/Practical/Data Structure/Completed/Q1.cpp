#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>
class ArrayClass
{
private :
	T * Array;
	int Size;

public :
	ArrayClass(int Size)
	{
		this->Size = Size;
		Array = new T[Size];
	}
	
	void DisplayArray()
	{
		cout << "Array : ";
		for (int i = 0; i < Size ; ++i)
			cout << " " << Array[i];
	}
	
	void InputArray()
	{
		cout << endl << "Enter the Elements of the Array : " << endl;
		
		for(int i = 0; i < Size; ++i)
		{
			cout << "Enter value for Array[" << i << "] : ";
			cin >> Array[i];
		}
	}
};

int main()
{
	ArrayClass <int> Ob(10);
	
	Ob.InputArray();
	Ob.DisplayArray();
	
	cout << endl;
	return 0;
}

 
