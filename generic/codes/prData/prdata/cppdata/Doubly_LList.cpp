#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

enum TypeOfLList{ Singly, Doubly, Circular};

class LLNode
{
private:
	int p_data; 
	LLNode* p_next;      

public:
	LLNode() 
	{
		p_data = 0;    
		p_next = NULL; 
	}
	LLNode(int data) 
	{
		p_data = data; 
		p_next = NULL; 
	}
	int Data()
	{
		return p_data;
	}
	LLNode * Next() 
	{
		return p_next;
	}
	void SetData(int data) 
	{
		p_data = data;
	}
	void SetNext(LLNode * next) 
	{
		p_next = next;
	}

};

class DoublyLLNode
{
private:
	int p_data; 
	DoublyLLNode * p_next;      
	DoublyLLNode * p_prev;
	
public:
	DoublyLLNode() 
	{
		p_data = 0;    
		p_next = NULL; 
		p_prev = NULL;
	}
	DoublyLLNode(int data) 
	{
		p_data = data; 
		p_next = NULL; 
		p_prev = NULL;
	}
	int Data()
	{
		return p_data;
	}
	DoublyLLNode * Next() 
	{
		return p_next;
	}
	DoublyLLNode * Prev() 
	{
		return p_prev;
	}
	void SetData(int data) 
	{
		p_data = data;
	}
	void SetNext(DoublyLLNode* next) 
	{
		p_next = next;
	}
	void SetPrev(DoublyLLNode* prev) 
	{
		p_prev = prev;
	}
};

class LList
{
private:
	LLNode * p_first;
	DoublyLLNode * pD_first; 
	TypeOfLList type;

public:
	LList(TypeOfLList type)
	{
		this->type = type;
		p_first = NULL;
		pD_first = NULL;
	}
	
	void AddItem(int data) 
	{
		switch (type)
		{
			case Singly :
			{
				AddItemToSinglyList(data);
				break;
			}
			case Doubly :
			{
				AddItemToDoublyList(data);
				break;
			}
			case Circular :
			{
				AddItemToCircularList(data);
				break;
			}
		}
	}
	
	void AddItemToSinglyList(int data)
	{
		if(!p_first)            
			p_first = new LLNode(data); 
		else                          
		{
			LLNode* current = p_first;     
			
			while(current->Next() != NULL) 
				current = current->Next();   
			
			LLNode* prev = current;        
			current = new LLNode(data);    
			prev->SetNext(current);        
		}
	}
	
	void AddItemToDoublyList(int data)
	{
		if(!pD_first)
		{
			pD_first = new DoublyLLNode(data);
		}
		else                          
		{
			DoublyLLNode * current = pD_first;     
			
			while(current->Next() != NULL) 
				current = current->Next();   
			
			DoublyLLNode * prev = current;        
			current = new DoublyLLNode(data);    
			prev->SetNext(current);        
			current->SetPrev(prev);
		}
		
	}
	
	void AddItemToCircularList(int data)
	{
		if(!p_first)
		{
			p_first = new LLNode(data);
			p_first->SetNext(p_first);
		}
		else                          
		{
			LLNode * current = p_first;     
			
			while(current->Next() != p_first) 
				current = current->Next();   
			
			LLNode * prev = current;        
			current = new LLNode(data);    
			prev->SetNext(current);        
			current->SetNext(p_first);
		}
	}
	
	void DisplayData()
	{
		switch (type)
		{
			case Singly :
			{
				OfSingly();
				break;
			}
			case Doubly :
			{
				OfDoubly();
				break;
			}
			case Circular :
			{
				OfCircular();
				break;
			}
		}
	}
	
	void OfSingly()
	{
		LLNode* Temp = p_first;
		
		cout << endl << "Contents of LinkList : ";
		while(Temp != NULL)
		{
			cout << Temp->Data() << " ";
			Temp = Temp->Next();
		}
	}
	
	void OfDoubly()
	{
		DoublyLLNode * Temp = pD_first;
		
		cout << endl << "Contents of Doubly LinkList : ";
		while(Temp != NULL)
		{
			cout << Temp->Data() << " ";
			Temp = Temp->Next();
		}	
	}
	
	void OfCircular()
	{
		LLNode * Temp = p_first;
		
		cout << endl << "Contents of Circular LinkList : ";
		while(Temp->Next() != p_first)
		{
			cout << Temp->Data() << " ";
			Temp = Temp->Next();
		}
		cout << Temp->Data() << " ";
	}
};

int main()
{
	LList Link_ListS(Singly);
	LList Link_ListD(Doubly);
	LList Link_ListC(Circular);
	
	char ans = 'y';
	unsigned int n;
	
	while(tolower(ans) != 'n')
	{
		cout << "Enter Data to Enter : ";
		cin >> n;
		Link_ListS.AddItem(n);
		Link_ListD.AddItem(n);
		Link_ListC.AddItem(n);
		
		cout << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	Link_ListS.DisplayData();
	
	Link_ListD.DisplayData();
	
	Link_ListC.DisplayData();	
	
	cout << endl;
	
	return 0;
} 
