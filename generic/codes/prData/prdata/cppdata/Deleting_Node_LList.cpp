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
	
	void DeleteNode(int NodeNo)
	{
		if(P_First == NULL)
		{
			cout << endl << endl << "!!!LinkList doesn't content any data" << endl << endl;
		}
		else
		{
			if(NodeNo == 1 && P_First != NULL)
			{
				LLNode * deleting = P_First;
				
				P_First = P_First->Next();
				
				delete deleting;
			}
			else
			{
				int i = 0;
				LLNode * temp = P_First;
			
				while((i < NodeNo - 2) && (temp->Next() != NULL))
				{
					++i;
					temp = temp->Next();
				}
				
				if((i == NodeNo - 2) && (temp->Next() != NULL))
				{
					LLNode * deleting = temp->Next();
					temp->SetNext(temp->Next()->Next());
					
					delete deleting;
				}
				else
					cout << endl << endl << "!!!Node : " << NodeNo << " does not exists" << endl << endl;
			}
		}
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
		cout << endl;
	}
};

int main()
{
	LList Link_List;
	char ans = 'y';
	unsigned int n;
	
	while(tolower(ans) != 'n')
	{
		cout << "Enter Data to Add : ";
		cin >> n;
		Link_List.AddItem(n);
		
		cout << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << endl << "Entered Data : ";
	Link_List.DisplayData();
	
	ans = 'y';
	
	while(tolower(ans) != 'n')
	{
		cout << "Enter Node Position to Del : ";
		cin >> n;
		
		cout << endl << endl << "Deleting Node : " << n;
		Link_List.DeleteNode(n);
	
		Link_List.DisplayData();
		
		cout << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << endl;
	
	return 0;
}