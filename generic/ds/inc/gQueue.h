#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <vector>

namespace gen { namespace ds { namespace queue {

template <class T>
class gQueue
{
private :
	vector<T>  	__data;
	s32_t		__head;
	s32_t		__tail;
	
public :
	gQueue(int Size);
	void push(T Data);
	T& top();
	bool empty();
};

template < class T >
gQueue<T>::gQueue(int Size)
{
	Data = new T[Size];
	Head = -1;
	Tail = -1;
	MaxSize = Size;
}
	
template < class T >
void gQueue<T>::InsertData(T Data)
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
	
template < class T >
int gQueue<T>::GetData()
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

template < class T >
bool gQueue<T>::MoreData()
{
	return (Tail == -1) ? false : true;
}
}
}}} //gen::ds::queue

#endif //_QUEUE_H_
