#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class  T>
class ArrayClass
{
private :
	int * Array;
	int Size;
public :
	ArrayClass()
	{
		Array = new T(10);
		Size = -1;
	}

	void AddData()
	{
		cout << endl << "\tEnter the elements of the array : ";
		for(int i = 0; i < 10; ++i)
			cin >> Array[i];
		++Size;
	}
	
	int RetSize()
	{
		return Size;
	}
	
	void DisplayArray()
	{
		cout << " Array : ";
		for (int i = 0; i < 10 ; ++i)
			cout << " " << Array[i];
	}

	void SortData(int no)
	{
		int temp = Array[10 - no];
		int i;
		int sub = 10 - no;
		
		if (no == 1)
			return;
		else
		{
			for(i = 10 - 1; i > 10 - no; --i)
				if(temp >= Array[i])
				{
					sub = i;
					temp = Array[i];
				}
			Array[sub] = Array[10 - no];
			Array[10 - no] = temp;
			SortData(no - 1);
		}
	} 
	
	bool BinarySearch(const T key, 
			const int StartSubscript = 0, const int LastSubscript = 9)
	{
		if (StartSubscript >= LastSubscript) 
			return ( Array[LastSubscript] == key ) ? true : false;
		else if ( Array[ (LastSubscript + StartSubscript)/ 2 ] == key)
			return true;
		else if ( Array[ (LastSubscript + StartSubscript)/ 2 ] > key)
			return (BinarySearch(key, StartSubscript,
					(( LastSubscript + StartSubscript ) / 2 ))) ? 
				true : false;  
		else if ( Array[ (LastSubscript + StartSubscript)/ 2 ] < key)
			return (BinarySearch(key, 
					(( LastSubscript + StartSubscript ) / 2 ) + 1,
					LastSubscript) ) ? 
				true : false;  
	}
	
	bool LinearSearch(const T key, const int Pos)
	{
		return ((Array[Pos - 1] == key) ? true : ((Pos < 0) ? false : LinearSearch(key, Pos - 1)));
	}
	
	void operator=(ArrayClass Ob)
	{
		for(int i = 0; i < 10; ++i)
			Array[i] = Ob.Array[i];
	}
};

int main()
{
	ArrayClass <int> Array;
	char ans;
	int key;
	
	Array.AddData();
	
	cout << endl << "Enter Data to find : ";
	cin >> key;
	
	if(Array.BinarySearch(key))
		cout << endl << "Found (Binary Search) : " << key << " : in the List";
	else 
		cout << endl << "Not Found (Binary Search) : " << key << " : in the List";
	
	if(Array.LinearSearch(key, Array.RetSize()))
		cout << endl << "Found (Linear Search ): " << key << " : in the List";
	else 
		cout << endl << "Not Found (Linear Search) : " << key << " : in the List";
	
	cout << endl;
	return 0;
}