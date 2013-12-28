#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

namespace gen { namespace ds { namespace llNode {

template < class T > 
class gLLNode {
private:
	T			__data;
	gLLNode * 	__pNext;
public:
	gLLNode(void); 
	gLLNode(const T data);

	void setData(const T data);
	T& getData()
	void setNext(gLLNode* next);
	gLLNode* getNext(void);
};

template < class T >
gLLNode<T>::gLLNode(void)
	: __data(0)
	, __pNext(NULL)
{
}

template < class T >
gLLNode<T>::gLLNode(const T data)
	: __data(data)
	, __pNext(NULL)
{
}

template < class T >
void gLLNode<T>::setData(const T data)
{
	__data = data;
}

template < class T >
T& gLLNode<T>::getData(void)
{
	return __data;
}

template < class T >
void gLLNode<T>::setNext(gLLNode* next)
{
	__pNext = next;
}

template < class T >
gLLNode* gLLNode<T>::setNext(void)
{
	return __pNext;
}

template < class T >
class gLList
{
private:
	gLLNode<T> *__pHead;
	u32_t	 	__size;

private:
	void cleanUp();
public:
	gLList();
	~gLList();
	
	u32_t	size();	
	void	clean();	

	void push_back(T&); 
	
	int deleteitem(unsigned int data) 
	{
		if(p_first == NULL) 
			return 0;   
	
		gLLNode* current = p_first; 
	
		if(current->data() == data)
		{
			int temp;
			temp = p_first->data();
			p_first = current->next(); 
			delete current;            
			return temp;                  
		}
	
		while(current->next() != NULL &&   
			current->next()->data() != data) 
			current = current->next();       
	
		if(current->next() != NULL)
		{
			int temp;
			gLLNode* prev = current;
			current = current->next();
			prev->setnext(current->next());
			temp = p_first->data();
			delete current;                
			return temp;                      
		}
		
		return 0; 
	}
	
	gLLNode* search(unsigned int data) 
	{
		gLLNode* current = p_first;
		
		while(current != NULL)    
		{
			if(current->data() == data) 
				return current;     
			current = current->next();  
		}
		return NULL;
	}
	
	bool insertitem(unsigned int prevdata, unsigned int data) 
	{
		gLLNode* prev = search(prevdata); 
		
		if(prev == NULL)                 
			return 0;                
	
		gLLNode* next = prev->next();     
		gLLNode* current = new gLLNode(data);
		prev->setnext(current);            
		current->setnext(next);            
		
		return 1; 
	}
	void insertfirst(unsigned int data) 
	{
		gLLNode* current = new gLLNode(data); 
		current->setnext(p_first);          
		p_first = current;                  
	}
	
	void display_data(void)
	{
		gLLNode* Temp = p_first;
		
		cout << endl << "Contents of Nodes : ";
		while(Temp != NULL)
		{
			cout << Temp->data() << " ";
			Temp = Temp->next();
		}
	}
	
	void display_Address()
	{
		gLLNode* Temp = p_first;
		
		cout << endl << "Address of Link List Nodes : ";
		while(Temp != NULL)
		{
			cout << Temp->next() << " ";
			Temp = Temp->next();
		}
	}
	
	void Rev_Link_List()
	{
		if(!p_first)
			cout << endl << "Nothing to Reverse";
		else
			if(!p_first->next())
				cout << endl << "Can't Reverse just One";
			else
			{
				Stack <gLLNode *> LStack(gLList_Size() + 1);
				gLLNode * temp = p_first;     
				
				while(temp->next() != NULL)
				{
					
					LStack.Push_Data(temp);
					temp = temp->next();
				}
				
				p_first = temp;
				
				while(LStack.Ret_Top() != -1)
				{
					temp->setnext(LStack.Pop_Data());
					temp = temp->next();
				}
				
				temp->setnext(NULL);
			}
	}
};

template < class T >
void gLList<T>::cleanUp(void)
{
	gLLNode* current = __pHead; 
	gLLNode* deleting;          

	while(current != NULL) 
	{
		deleting = current;        
		current = current->getNext(); 
		delete deleting;           
	}

	__size = 0;
}

template < class T>
gLList<T>::gLList()
	: __pHead(NULL)
	, __size(0)
{
}

template <class T>
gLList<T>::~gLList()
{
	cleanUp();
}

template < class T >
void gLList<T>::push_back(T& data)
{
	if(!__pHead)
	{ 
		__pHead = new gLLNode(data);
		++__size;
	}
	else                          
	{
		gLLNode* current = __pHead;     
		
		while(current->getNext() != NULL) 
			current = current->getNext();   
		
		gLLNode* prev = current;        
		current = new gLLNode(data);    
		prev->setNext(current);        
	}
}

}}} //gen::ds::llNode namespace

#endif
