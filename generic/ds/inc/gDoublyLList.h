#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_
#include <iostream>

using namespace std;

namespace gen { namespace ds { namespace doublyLinkedList {

template <class T>
class DoublyLinkedListNodeT
{
public:
    DoublyLinkedListNodeT() //default Constructor
	:    __pPrevNode(NULL)
    ,    __pNextNode(NULL)
    {}
    DoublyLinkedListNodeT(DoublyLinkedListNodeT prevNode, DoublyLinkedListNodeT nextNode, T data) //Constructor
	:    __pPrevNode(prevNode)
    ,    __pNextNode(nextNode)
	,	 __data(data)
    {}

    DoublyLinkedListNodeT* 	getPrevNode(void) 	{ return __pPrevNode; } 
    DoublyLinkedListNodeT* 	getNextNode(void) 	{ return __pNextNode; }
    T 						getData(void) 		{ return __data; }

    void setPrevNode(DoublyLinkedListNodeT* prevNode) 	{ __pPrevNode = prevNode; }
	void setNextNode(DoublyLinkedListNodeT* nextNode) 	{ __pNextNode = nextNode; }
	void setData(T data) 								{ __data = data; }

private:
    DoublyLinkedListNodeT* __pPrevNode;
    DoublyLinkedListNodeT* __pNextNode;

    T __data;
};

template <class T>
class DoublyLinkedListT
{
	public:
		DoublyLinkedListT() //default Constructor 
		:    __pHead(NULL)
		,	 __size(0)
		{}
		DoublyLinkedListT(const DoublyLinkedListT<T>& obj) //Copy Constructor
		{ copyData(obj); }
		
		virtual ~DoublyLinkedListT()
		{
			while(__size-- && __pHead)
			{
				DoublyLinkedListNodeT <T> * pDel = __pHead;
				__pHead = __pHead->getNextNode();
				delete pDel;
			}
		}
		
		DoublyLinkedListT<T> & operator=(const  DoublyLinkedListT<T>& obj)
		{
			if (&obj != this)
				copyData(obj);
			return *this;
		}

		void addNodeAtFront(T data)
		{
			DoublyLinkedListNodeT <T>  * temp = new DoublyLinkedListNodeT<T>();
			temp->setData(data);
			temp->setPrevNode(NULL);
			temp->setNextNode(NULL);

			if (__pHead == NULL)
				__pHead = temp;
			else
			{
				temp->setNextNode(__pHead);
				__pHead = temp;
			}
			++__size;
		}

		void deleteNodeFromFront(void)
		{
			if (__pHead == NULL)
			{
				__size = 0;
				return;
			}
			if (!__pHead->getNextNode())
				delete __pHead;
			else		
			{
				__pHead = __pHead->getNextNode();
				delete __pHead->getPrevNode();
				__pHead->setPrevNode(NULL);
			}
			--__size;
		}

		void addNodeAtEnd(T data)
		{
			DoublyLinkedListNodeT <T>  * temp = new DoublyLinkedListNodeT<T>();
			temp->setData(data);
			temp->setPrevNode(NULL);
			temp->setNextNode(NULL);

			if (__pHead == NULL)
				__pHead = temp;
			else
			{
				DoublyLinkedListNodeT <T>  * tempNode = __pHead;

				while (tempNode->getNextNode() != NULL)
				{
					tempNode = tempNode->getNextNode();
				}

				temp->setPrevNode(tempNode);
				tempNode->setNextNode(temp);
			}
			++__size;
		}

		void deleteNodeFromEnd(void)
		{
			if (__pHead == NULL)
			{
				__size = 0;
				return;
			}
			if (!__pHead->getNextNode())
				delete __pHead;
			else		
			{
				DoublyLinkedListNodeT <T>  * tempNode = __pHead;

				while (tempNode->getNextNode() != NULL)
				{
					tempNode = tempNode->getNextNode();
				}

				tempNode->getPrevNode()->setNextNode(NULL);

				delete tempNode;
			}
			--__size;
		}

		DoublyLinkedListNodeT <T> * getHead(void);
		int 						getSize(void);

		bool	reverseList()
		{
			if (!__size)
				return true;
			DoublyLinkedListNodeT <T>  * pTempHead = __pHead;
			while(pTempHead->getNextNode())
			{
				DoublyLinkedListNodeT <T>  * pTempSwap = pTempHead->getNextNode();
				pTempHead->setNextNode(pTempHead->getPrevNode());
				pTempHead->setPrevNode(pTempSwap);
				pTempHead = pTempHead->getPrevNode();
			}

			DoublyLinkedListNodeT <T>  * pTempSwap = pTempHead->getNextNode();
			pTempHead->setNextNode(pTempHead->getPrevNode());
			pTempHead->setPrevNode(pTempSwap);
			__pHead = pTempHead;
			return true;
		}

		void printList()
		{
			cout << endl << "DoublyLinkedList -> ";
			
			DoublyLinkedListNodeT <T>  * pTempHead = __pHead;
			while(pTempHead)
			{
				cout << pTempHead->getData() << " -> ";
				pTempHead = pTempHead->getNextNode();
			}
			cout << "NULL" << endl;
		}

	private:
		void	copyData(const  DoublyLinkedListNodeT <T> & obj)
		{
			DoublyLinkedListNodeT <T>  * pTempHead = obj.__pHead;
			while(pTempHead)
			{
				addNodeAtEnd(pTempHead->getData());
				pTempHead = pTempHead->getNextNode();
			}
			this->__size = obj.__size;
		}
	private:
		DoublyLinkedListNodeT <T>  *__pHead;
		int 						__size;
};

}}} //gen::namespace::doublyLinkedList

#endif //_DOUBLY_LINKED_LIST_
