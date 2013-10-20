 
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>
class CircularQueue
{
private :
	T * Data;
	int Head;
	int Tail;
	int MaxSize;
	
public :
	CircularQueue(int Size)
	{
		Data = new T[Size];
		Head = -1;
		Tail = -1;
		MaxSize = Size;
	}
	
	void InsertData(T Data)
	{
		if(Head == -1)
		{
			Head = 0;
			Tail = 0;
		}
		else
			if( Head !=  ((Tail + 1) %  MaxSize))
			{
				++Tail;
				Tail = (Tail >= MaxSize) ? Tail % MaxSize : Tail;
			}
			else
			{
				cout << endl << "Overflow";
				return;
			}
			
		this->Data[Tail] = Data;
	}
	
	int GetData()
	{
		int temp;
		
		if(Head == -1)
		{
			cout << endl << "Underflow";
			return 0;
		}
		else
			if(Tail == Head)
			{
				temp = Data[Head];
				Head = -1;
				Tail = -1;
				return temp;
			}
			else
			{
				temp = Data[Head++];
				Head = (Head >= MaxSize) ? Head % MaxSize : Head;
				return temp;
			}
	}
	
	bool MoreData()
	{
		return (Tail == -1) ? false : true;
	}
};

int main()
{
	CircularQueue <int> Que(5);
	int n;
	char ans = ' ';
	char ans1 = ' ';
	char ans2 = ' ';
	
	while(tolower(ans) != 'n')
	{
		while(tolower(ans1) != 'n')
		{
			cout << endl << "Enter Data to Push : ";
			cin >> n;
			Que.InsertData(n);
			cout << endl << "Do U want to Continue(y/n)";
			cin >> ans1;
		}
		
		cout << endl << "Do U want to Delete item(y/n) : ";
		cin >> ans2;
		
		if((tolower(ans2) == 'y') && (Que.MoreData()))
			cout << endl << "Poped out Data : " << Que.GetData();
			
		cout << endl << "Do U want to Continue(y/n)";
		cin >> ans;
		cout << endl << "Do U want to EnterData(y/n)";
		cin >> ans1;
	}
	
	cout << endl;
	
	return 0;
}


 
