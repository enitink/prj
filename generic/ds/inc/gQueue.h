#ifndef _QUEUE_H_
#define _QUEUE_H_

namespace gen { namespace ds { namespace queue {

template <class T>
class gQueue
{
private :
	T * Data;
	int Head;
	int Tail;
	int MaxSize;
	
public :
	gQueue(int Size)
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
			if(Tail != MaxSize)
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

}}} //gen::ds::queue

#endif //_QUEUE_H_
