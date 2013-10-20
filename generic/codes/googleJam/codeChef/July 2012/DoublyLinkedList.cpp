#define null 0

template <class T>
class DoublyLinkedListNodeT
{
public:
    DoublyLinkedListNodeT()
    :    __pPrevNode(null)
    ,    __pNextNode(null)
    {
    }
    virtual ~DoublyLinkedListNodeT(){}

    DoublyLinkedListNodeT* GetPrevNode(void)
    {
        return __pPrevNode;
    }

    DoublyLinkedListNodeT* GetNextNode(void)
    {
        return __pNextNode;
    }

    void SetPrevNode(DoublyLinkedListNodeT* prevNode)
    {
        __pPrevNode = prevNode;
    }

    void SetNextNode(DoublyLinkedListNodeT* nextNode)
    {
        __pNextNode = nextNode;
    }

    T GetData(void)
    {
        return __data;
    }

    void SetData(T data)
    {
        __data = data;
    }

private:
    DoublyLinkedListNodeT* __pPrevNode;
    DoublyLinkedListNodeT* __pNextNode;

    T __data;
};

template <class T>
class DoublyLinkedListT
{
public:
    DoublyLinkedListT()
    :    __pHead(null)
	,	 __size(0)
    {
    }
    virtual ~DoublyLinkedListT(){}

    void AddNodeAtFront(T data)
    {
        DoublyLinkedListNodeT <T>  * temp = new DoublyLinkedListNodeT<T>();
        temp->SetData(data);
        temp->SetPrevNode(null);
        temp->SetNextNode(null);

        if (__pHead == null)
            __pHead = temp;
        else
        {
		temp->SetNextNode(__pHead);
		__pHead = temp;
        }
		++__size;
    }

	void DeleteNodeFromFront(void)
	{
		if (__pHead == null)
		{
			__size = 0;
			return;
		}
		if (!__pHead->GetNextNode())
			delete __pHead;
		else		
		{
			__pHead = __pHead->GetNextNode();
			delete __pHead->GetPrevNode();
			__pHead->SetPrevNode(null);
		}
		--__size;
	}

	void AddNodeAtEnd(T data)
    {
        DoublyLinkedListNodeT <T>  * temp = new DoublyLinkedListNodeT<T>();
        temp->SetData(data);
        temp->SetPrevNode(null);
        temp->SetNextNode(null);

        if (__pHead == null)
            __pHead = temp;
        else
        {
            DoublyLinkedListNodeT <T>  * tempNode = __pHead;

            while (tempNode->GetNextNode() != null)
            {
                tempNode = tempNode->GetNextNode();
            }

            temp->SetPrevNode(tempNode);
            tempNode->SetNextNode(temp);
        }
		++__size;
    }

	void DeleteNodeFromEnd(void)
	{
		if (__pHead == null)
		{
			__size = 0;
			return;
		}
		if (!__pHead->GetNextNode())
			delete __pHead;
		else		
		{
			DoublyLinkedListNodeT <T>  * tempNode = __pHead;

		    while (tempNode->GetNextNode() != null)
		    {
		        tempNode = tempNode->GetNextNode();
		    }
			
			tempNode->GetPrevNode()->SetNextNode(null);

			delete tempNode;
		}
		--__size;
	}

    void MoveHead(int place, bool forward = true)
    {
        int i = 0;
		DoublyLinkedListNodeT <T>  * tempNode = __pHead;

        for ( ; i < place; ++i)
		{
			if ( (forward && tempNode->GetNextNode() == null) || (!forward && tempNode->GetPrevNode() == null) )
				break;
			tempNode = (forward) ? tempNode->GetNextNode() : tempNode->GetPrevNode();
		}

		__pHead = tempNode;
    }

	DoublyLinkedListNodeT <T> * GetHead(void)
	{
		return __pHead;
	}

	int GetSize(void)
	{
		return __size;
	}

private:
    DoublyLinkedListNodeT <T>  *__pHead;

	int __size;
};
