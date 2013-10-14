#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>
#include <CommonDefs.h>
#include <commonUtils.h>

using namespace std;
using namespace gen::common::defs;
using namespace gen::common::utils;

namespace gen { namespace ds { namespace heap {

typedef enum
{
	MAX_HEAP,
	MIN_HEAP
}heapType_e;

template <class T>
class gHeap
{
private:
	u32_t 		__size;
	heapType_e	__heapType;
	vector<T>  	__data;
private:
	bool createHeap();
	bool updateHeap();
	bool updateOnInsert();
public:
	gHeap(heapType_e);
	gHeap(heapType_e,const T [], u32_t);
	virtual ~gHeap();

	bool insert(const T&);
	bool merge(const gHeap<T> &);
	bool empty();
	bool pop();
	T& top();

	void print();
};

template < class T >
bool gHeap<T>::createHeap()
{
	int i, j, k;
	switch (__heapType)
	{
	case MAX_HEAP:
	{
		for(i = 1; i < __size; ++i)
		{
			j = (i - 1) / 2;
			k = i;
			while( __data[j] < __data[k] )
			{
				gSwap( __data[j], __data[k] );
				k = j;
				j = (j - 1) / 2;
				if( k < 0 || j < 0 )
					break;
			}
		}
	}
	break;
	case MIN_HEAP:
	{
		for(i = 1; i < __size; ++i)
		{
			j = (i - 1) / 2;
			k = i;
			while( __data[j] > __data[k] )
			{
				gSwap( __data[j], __data[k] );
				k = j;
				j = (j - 1) / 2;
				if( k < 0 || j < 0 )
					break;
			}
		}
	}
	break;
	}
	return true;
}

template < class T >
bool gHeap<T>::updateHeap()
{
    u32_t root, left, right, max = 0;
    do
    {
        root = max;
        left = 2 * root + 1;
        right = 2 * root + 2;
        if( left >= __size)
            break;
        if( right >= __size )
            max = left;
        else if (__heapType == MAX_HEAP)
            max = __data[left] > __data[right] ? left : right;
		else
            max = __data[left] < __data[right] ? left : right;
        if( ((__heapType == MAX_HEAP) && ( __data[max] < __data[root])) || 
			((__heapType == MIN_HEAP) && ( __data[max] > __data[root])) )
            break;
        gSwap( __data[max], __data[root] );
    }while(1);
    return true;
}

template < class T >
bool gHeap<T>::updateOnInsert()
{
    int parent, current = __size - 1;
	
    do
    {
        parent = (current - 1) / 2 ;
        if (current == 0)
			break;
        if( ((__heapType == MAX_HEAP) && ( __data[parent] > __data[current])) || 
			((__heapType == MIN_HEAP) && ( __data[parent] < __data[current])) )
            break;
        gSwap( __data[parent], __data[current] );
		current = parent;
    }while(1);
    return true;
}

template < class T >
gHeap<T>::gHeap(heapType_e aType) : __size(0), __heapType(aType)
{
	__data.clear();
}

template < class T >
gHeap<T>::gHeap(heapType_e aType, const T arr[], u32_t aSize) : __size(0), __heapType(aType)
{
	__data = vector <T> (arr, arr + aSize);
	__size = aSize;
	createHeap();
}

template < class T >
gHeap<T>::~gHeap()
{
	__data.clear(); //clearing data
}

template < class T >
bool gHeap<T>::insert(const T& aData)
{
	__data.push_back(aData);
	++__size;
	if (__size > 1)
	{
		return updateOnInsert();
	}
	return true;
}

template < class T >
bool gHeap<T>::merge(const gHeap<T>& aHeap)
{
	return false;
}

template < class T >
bool gHeap<T>::empty()
{
	return (__size) ? true : false;	
}

template < class T >
bool gHeap<T>::pop()
{
	if (!__size)
		return false;
	__data[0] = __data[__size - 1];
	--__size;
	__data.erase(__data.end() - 1);
	return updateHeap();
}

template < class T >
T& gHeap<T>::top()
{
	return __data[0];
}

template < class T >
void gHeap<T>::print()
{
	for (typename vector<T>::iterator it = __data.begin(); it != __data.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

}}} //gen::ds::heap namespace

#endif //_HEAP_H_
