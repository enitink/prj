#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

class SortArray
{
private:
	int * Array;
	int Size;
	
public:
	SortArray(int Size)
	{
		this->Size=Size;
		Array = new int[Size];
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
	
	int RetVal(int Pos)
	{
		return Array[Pos - 1];
	}
	
	int RetSize()
	{
		return Size;
	}
	
	void HeapSort()
	{
	
	}
	
	void SwapNos(int *a, int *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;	
	}
	
	void QuickSort(int SSubs, int LSubs)
	{
		int Position = SSubs;
		int CounterR = 0, CounterL = LSubs + 1;
		
		if (SSubs >= LSubs - 1)
			return;
		else
		{
			int Check = 1;
			while (Check != 0)
			{
				CounterR = CounterL - 1;
				
				do
				{
					Check = 0;
					if (Array[Position] > Array[CounterR])
					{
						SwapNos(&Array[Position], &Array[CounterR]);
						CounterL = Position + 1;
						Position = CounterR;
						++Check;
						break;
					}
					--CounterR;
				}while(CounterR >= Position);
				
				do
				{
					Check = 0;
					if (Array[Position] < Array[CounterL])
					{
						SwapNos(&Array[Position], &Array[CounterL]);
						SwapNos(&Position, &CounterL);
						++Check;
						break;
					}
					++CounterL;
				}while(CounterL <= Position);
			}
			
			if (Position - 1 >= SSubs)
				QuickSort(SSubs, Position - 1);
			
			if (Position + 1 <= LSubs)
				QuickSort(Position + 1, LSubs);		
		}
	} 
	
	void SelectionSort(int No)
	{
		int temp = Array[Size - No];
		int i;
		int sub = Size - No;
		
		if (No == 1)
			return;
		else
		{	
			for(i = Size - 1; i > Size - No; --i)
				if(temp >= Array[i])
				{
					sub = i;
					temp = Array[i];
				}
			Array[sub] = Array[Size - No];
			Array[Size - No] = temp;
			SelectionSort(No - 1);
		}
	} 
	
	void BubbleSort()
	{
		for(int i = 0; i < Size; ++i)
		{
			for(int j = 0; j < Size - i - 1; ++j)
			{
				if(Array[j] > Array[j + 1])
				{
					Array[j] = Array[j] ^ Array[j + 1];
					Array[j + 1] = Array[j] ^ Array[j + 1];
					Array[j] = Array[j] ^ Array[j + 1];
				}
			}
		}
	}
	
	void MergeArray(int Spos1, int Lpos1, int Spos2, int Lpos2)
	{
		int i = Spos1, j = Spos2, k = Spos1 - 1;
		SortArray Object(RetSize());
		
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
	SortArray Ob(10);
	
	Ob.InputArray();
	Ob.DisplayArray();
	
	Ob.MergeSort(0, Ob.RetSize() - 1);
	
	cout << endl << "Greatest No : " << Ob.RetVal(Ob.RetSize());
	cout << endl << "Smallest No : " << Ob.RetVal(0);
	
	cout << endl;
	return 0;
}