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
		return Size - 1;
	}

	void DisplayArray()
	{
		cout << endl << "Array : ";
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
		int i = Spos1, j = Spos2, k = Spos1 - 1;
		Merge <int> Object(RetSize());
		
		for( ; i <= Lpos1 && j <= Lpos2; )
		{
			if(Array[i] < Array[j])
				Object.Array[++k] = Array[i++];
			else
				if(Array[i] > Array[j])
					Object.Array[++k] = Array[j++];
				else
				{
					Object.Array[++k] = Array[i++];
					Object.Array[++k] = Array[j++];
				}
		}
		
		while(j <= Lpos2)
			Object.Array[++k] = Array[j++];
		while(i <= Lpos1)
			Object.Array[++k] = Array[i++];
		
		while(k >= Spos1)
			Array[k] = Object.Array[k--];
	}

	void MergeSort(int Spos, int Lpos)
	{
		if(Spos < Lpos)
		{
			MergeSort(Spos, (Spos + Lpos) / 2);
			MergeSort(((Spos + Lpos) / 2) + 1, Lpos);
			MergeArray(Spos, (Spos + Lpos) / 2, ((Spos + Lpos) / 2) + 1, Lpos);
		}
		else
			return;
	}
};

int main()
{
	int n;
	cout << endl << "Enter Size : ";
	cin >> n;
	Merge <int> Ob(n);

	Ob.InputArray();
	Ob.DisplayArray();

	cout << endl << "Sorted Array : ";
	Ob.MergeSort(0, Ob.RetSize());
	Ob.DisplayArray();
	
	cout << endl;
	return 0;
}
