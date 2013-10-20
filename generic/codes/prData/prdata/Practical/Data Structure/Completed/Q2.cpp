 
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
		this->Size=Size;
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
			cout << "Enter value for Array[" << i + 1 << "] : ";
			cin >> Array[i];
		}
	}
	
	void DeleteElement(int Ele_Del_Index)
	{
		if(Ele_Del_Index - 1 >= Size)
			cout << endl << "Array Out of Bound";
		else
		{
			for(int i = Ele_Del_Index - 1; i < Size; ++i)
				Array[i] = Array[i + 1];
		}
		Size--;
	}
};

int main()
{
	ArrayClass <int> Ob(10);
	int Pos;
	
	Ob.InputArray();
	Ob.DisplayArray();
	
	cout << endl << "Enter The Position to Delete the Element :";
	cin >> Pos;
	
	Ob.DeleteElement(Pos);
	Ob.DisplayArray();
	
	cout << endl;
	return 0;
}

 
