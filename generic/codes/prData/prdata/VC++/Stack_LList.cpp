#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

class LLNode
{
private:
	unsigned int p_data; 
	LLNode * p_next;      

public:
	LLNode() 
	{
		p_data = 0;    
		p_next = NULL; 
	}
	LLNode(unsigned int data) 
	{
		p_data = data; 
		p_next = NULL; 
	}
	unsigned int data(void) const 
	{
		return p_data;
	}
	LLNode* next(void) const 
	{
		return p_next;
	}
	void setdata(unsigned int data) 
	{
		p_data = data;
	}
	void setnext(LLNode * next) 
	{
		p_next = next;
	}

};

class LList
{
private:
	LLNode * p_first; 

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
		
		while(temp != NULL)
		{
			++i;
			temp = temp->next();
		}
		
		return i;
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
	
	int deleteitem() 
	{
		
		if(p_first == NULL) 
		{
			return 0;   
		}
		else
		{
			if(p_first->next() == NULL)
			{
				int temp = p_first->data();
				p_first = NULL;
				
				return temp;
			}
			else
			{
				LLNode * current = p_first; 
				
				while(current->next()->next() != NULL)
				{
					current = (current->next());     
				}
				
				int temp = current->next()->data();
				current->setnext(NULL);
				
				return temp; 
			}
		}
		
	}
		
	void display_data(void)
	{
		LLNode * Temp = p_first;
		
		cout << endl << "Contents of Nodes : ";
		while(Temp != NULL)
		{
			cout << Temp->data() << " ";
			Temp = Temp->next();
		}
		Temp = NULL;
	}
	
	void display_Address()
	{
		LLNode* Temp = p_first;
		
		cout << endl << "Address of Link List Nodes : ";
		
		cout << Temp << " ";
		while(Temp != NULL)
		{
			cout << Temp->next() << " ";
			Temp = Temp->next();
		}
		delete Temp;	
	}
};

class Stack
{
private :
	LList StackData;

public :
	void Push_Data(int  Data)
	{
		StackData.additem(Data);
	}
	
	int Pop_Data()
	{
		return (StackData.LList_Size() <= 0) ? 0 : StackData.deleteitem();
	}
	
	int Ret_Top()
	{
		return StackData.LList_Size() - 1;
	}
};

int main()
{
	Stack StackData;
	char ans = 'y';
	unsigned int n;
	
	while(tolower(ans) != 'n')
	{
		cout << endl << "Enter Data to Push : ";
		cin >> n;
		StackData.Push_Data(n);
		
		cout << endl << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << "Popping Data from Stack :";
	while(StackData.Ret_Top() > -1)
	{
		cout << "  " << StackData.Pop_Data();
	}
	
	cout << endl;
	cout << "\n";
	
	return 0;
}