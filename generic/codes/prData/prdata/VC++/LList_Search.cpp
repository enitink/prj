#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

class LLNode
{
private:
	int P_Data; 
	LLNode* P_Next;      

public:
	LLNode() 
	{
		P_Data = 0;    
		P_Next = NULL; 
	}
	LLNode(int Data) 
	{
		P_Data = Data; 
		P_Next = NULL; 
	}
	int Data() 
	{
		return P_Data;
	}
	LLNode* Next() 
	{
		return P_Next;
	}
	void SetData(int Data) 
	{
		P_Data = Data;
	}
	void SetNext(LLNode* Next) 
	{
		P_Next = Next;
	}

};

class LList
{
private:
	LLNode* P_First; 

public:
	LList()
	{
		P_First = NULL; 
	}
	~LList()
	{
		LLNode* current = P_First; 
		LLNode* deleting;          

		while(current != NULL) 
		{
			deleting = current;        
			current = current->Next(); 
			delete deleting;           
		}
	}
	
	LLNode* First() 
	{
		return P_First;
	}
	
	void AddItem(int Data) 
	{
		if(!P_First)            
			P_First = new LLNode(Data); 
		else                          
		{
			LLNode* current = P_First;     
			
			while(current->Next() != NULL) 
				current = current->Next();   
			
			LLNode* prev = current;        
			current = new LLNode(Data);    
			prev->SetNext(current);        
		}
	}
	
	LLNode * LinearSearch(int Data) 
	{
		LLNode* current = P_First;
		
		while(current != NULL)    
		{
			if(current->Data() == Data) 
				return current;     
			current = current->Next();  
		}
		return NULL;
	}
	
	void SortLList()
	{
		
	}
	
	void DisplayData()
	{
		LLNode* Temp = P_First;
		
		cout << endl << "Contents of Link List : ";
		while(Temp != NULL)
		{
			cout << Temp->Data() << " ";
			Temp = Temp->Next();
		}
	}
};

int main()
{
	LList Link_List;
	char ans = 'y';
	unsigned int n;
	
	while(tolower(ans) != 'n')
	{
		cout << "Enter Data to Enter : ";
		cin >> n;
		Link_List.AddItem(n);
		
		cout << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << endl << "Entered Data : ";
	Link_List.DisplayData();
		
	cout << endl;
	
	return 0;
} 
