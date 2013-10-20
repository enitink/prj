#define null 0

template <class T>
class CircularLinkedListNodeT
{
public:
    CircularLinkedListNodeT()
    :    __pPrevNode(null)
    ,    __pNextNode(null)
    {
    }
    virtual ~CircularLinkedListNodeT(){}

    CircularLinkedListNodeT* GetPrevNode(void)
    {
        return __pPrevNode;
    }

    CircularLinkedListNodeT* GetNextNode(void)
    {
        return __pNextNode;
    }

    void SetPrevNode(CircularLinkedListNodeT* prevNode)
    {
        __pPrevNode = prevNode;
    }

    void SetNextNode(CircularLinkedListNodeT* nextNode)
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
    CircularLinkedListNodeT* __pPrevNode;
    CircularLinkedListNodeT* __pNextNode;

    T __data;
};

template <class T>
class CircularLinkedListT
{
public:
    CircularLinkedListT()
    :    __pHead(null)
	,	 __size(0)
    {
    }
    virtual ~CircularLinkedListT(){}

    void AddNode(T data)
    {
        CircularLinkedListNodeT <T>  * temp = new CircularLinkedListNodeT<T>();
        temp->SetData(data);
        temp->SetPrevNode(temp);
        temp->SetNextNode(temp);

        if (__pHead == null)
            __pHead = temp;
        else
        {
            CircularLinkedListNodeT <T>  * tempNode = __pHead;

            temp->SetNextNode(__pHead);
            tempNode->SetPrevNode(temp);

            while (tempNode->GetNextNode() != __pHead)
            {
                tempNode = tempNode->GetNextNode();
            }

            temp->SetPrevNode(tempNode);
            tempNode->SetNextNode(temp);
        }
	++__size;
    }

    void MoveHead(int place, bool forward = true)
    {
        int i = 0;
		CircularLinkedListNodeT <T>  * tempNode = __pHead;

        for ( ; i < place; ++i)
		tempNode = (forward) ? tempNode->GetNextNode() : tempNode->GetPrevNode();

		__pHead = tempNode;
    }

	CircularLinkedListNodeT <T> * GetHead(void)
	{
		return __pHead;
	}

	int GetSize(void)
	{
		return __size;
	}

private:
    CircularLinkedListNodeT <T>  *__pHead;
	int __size;
};



