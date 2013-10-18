#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

template <class T>
class Stack{
private :
	T * NextAddress;
	int top;		
public :
	Stack()	{
		NextAddress = NULL;
		top = -1;
	}	
	Stack(int Size)	{
		top = -1;
		NextAddress = new T[Size + 3];
	}	
	void Push_Data(T  Address) {
		++top;
		NextAddress[top] = Address;
	}	
	T Pop_Data() {
		return (top == -1) ? NULL : NextAddress[top--];
	}	
	int Ret_Top() {
		return top;
	}
};

class LLNode {
private:
	unsigned int p_data; 
	LLNode * p_next;
public:
	LLNode() {
		p_data = 0;    
		p_next = NULL; 
	}
	LLNode(unsigned int data) {
		p_data = data; 
		p_next = NULL; 
	}
	unsigned int data(void) const {
		return p_data;
	}
	LLNode* next(void) const {
		return p_next;
	}
	void setdata(unsigned int data) {
		p_data = data;
	}
	void setnext(LLNode* next) {
		p_next = next;
	}

};

class LList
{
private:
	LLNode* p_first; 

public:
	LList()
	{
		p_first = NULL; 
	}
	~LList()
	{
		LLNode* current = p_first; 
		LLNode* deleting;          

		while(current != NULL) 
		{
			deleting = current;        
			current = current->next(); 
			delete deleting;           
		}
	}
	
	int LList_Size(void)
	{
		int i = 0;
		LLNode * temp = p_first;     
		
		while(temp->next() != NULL)
		{
			++i;
			temp = temp->next();
		}
		
		return i + 1;
	}
	
	LLNode* first(void) const 
	{
		return p_first;
	}
	
	void additem(unsigned int data) 
	{
		if(!p_first)            
			p_first = new LLNode(data); 
		else                          
		{
			LLNode* current = p_first;     
			
			while(current->next() != NULL) 
				current = current->next();   
			
			LLNode* prev = current;        
			current = new LLNode(data);    
			prev->setnext(current);        
		}
	}
	
	int deleteitem(unsigned int data) 
	{
		if(p_first == NULL) 
			return 0;   
	
		LLNode* current = p_first; 
	
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
			LLNode* prev = current;
			current = current->next();
			prev->setnext(current->next());
			temp = p_first->data();
			delete current;                
			return temp;                      
		}
		
		return 0; 
	}
	
	LLNode* search(unsigned int data) 
	{
		LLNode* current = p_first;
		
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
		LLNode* prev = search(prevdata); 
		
		if(prev == NULL)                 
			return 0;                
	
		LLNode* next = prev->next();     
		LLNode* current = new LLNode(data);
		prev->setnext(current);            
		current->setnext(next);            
		
		return 1; 
	}
	void insertfirst(unsigned int data) 
	{
		LLNode* current = new LLNode(data); 
		current->setnext(p_first);          
		p_first = current;                  
	}
	
	void display_data(void)
	{
		LLNode* Temp = p_first;
		
		cout << endl << "Contents of Nodes : ";
		while(Temp != NULL)
		{
			cout << Temp->data() << " ";
			Temp = Temp->next();
		}
	}
	
	void display_Address()
	{
		LLNode* Temp = p_first;
		
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
				Stack <LLNode *> LStack(LList_Size() + 1);
				LLNode * temp = p_first;     
				
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
