#define MAXSIZE 10
#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>
class Queue
{
private :
	T Data[MAXSIZE];
	int Head;
	int Tail;

public :
	Queue()
	{
		Head = -1;
		Tail = -1;
	}
	
	void InsertData(T Data)
	{
		if(Head == -1)
		{
			Head = 0;
			Tail = 0;
		}
		else
			if(Tail != MAXSIZE - 1)
				++Tail;
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
			if(Head == Tail)
			{
				temp = Data[Head];
				Head = -1;
				Tail = -1;
				return temp;
			}
			else
			{
				temp = Data[Head++];
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
	Queue <int> Que;
	int n;
	char ans = ' ';
	
	while(tolower(ans) != 'n')
	{
		cout << endl << "Enter Data to Push : ";
		cin >> n;
		Que.InsertData(n);
		
		cout << endl << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << "Getting Data out of Que :";
	while(Que.MoreData())
	{
		cout << "  " << Que.GetData();
	}
	
	
	cout << endl;
	
	return 0;
}


 
