#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>
class Merge
{
private :
	T * Array;
	int Size;

public :
	Merge(int Size)
	{
		this->Size=Size;
		Array = new T[Size];
	}
	
	int RetSize()
	{
		return Size;
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
	
	void MergeArray(int Spos1, int Lpos1, int Spos2, int Lpos2)
	{
		int i = Spos1, j = Spos2, k = 0;
		
		for( ; i < Size && j < Ob.Size; )
		{
			if(Array[i] < Ob.Array[j])
				Object.Array[k++] = Array[i++];
			else
				if(Array[i] > Ob.Array[j])
					Object.Array[k++] = Ob.Array[j++];
				else
				{
					Object.Array[k++] = Array[i++];
					Object.Array[k++] = Ob.Array[j++];
				}
		}
		while(j < Ob.Size)
			Object.Array[k++] = Ob.Array[j++];
		while(i < Size)
			Object.Array[k++] = Array[i++];
	}

	void MergeSort(int Spos, int Lpos)
	{
		if(Spos == Lpos)
			return;
		else
		{
			MergeSort(Spos, Lpos / 2);
			MergeSort((Lpos / 2) + 1, Lpos);
			MergeArray(
		}
	}
};

int main()
{
	Merge <int> Ob(15), Ob1(5);
	Merge <int> Ob2(20);
	
	Ob.InputArray();
	Ob.DisplayArray();
	Ob1.InputArray();
	Ob1.DisplayArray();
	
	Ob.MergeArray(Ob1, Ob2);
	Ob2.DisplayArray();
	
	cout << endl;
	return 0;
}