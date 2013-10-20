#include<iostream>
#include<cstring>

using std :: cin; 
using std :: cout;
using std :: endl;

enum TrType {PreOrder, InOrder, PostOrder};
class BSTreeNode
{
private :
	int Val;
	BSTreeNode * LNode;
	BSTreeNode * RNode;

public :
	BSTreeNode(int Val)
	{
		this->Val = Val;
		LNode = NULL;
		RNode = NULL;
	}

	void SetVal(int Val)
	{
		this->Val = Val;
	}
	
	void SetLNodeAdd(BSTreeNode * LNode)
	{
		this->LNode = LNode;
	}
	
	void SetRNodeAdd(BSTreeNode * RNode)
	{
		this->RNode = RNode;
	}
	
	int RetVal()
	{
		return Val;
	}
	
	BSTreeNode * RetLNodeAdd()
	{
		return LNode;
	}
	
	BSTreeNode * RetRNodeAdd()
	{
		return RNode;
	}
};

class BSTree
{
private :
	BSTreeNode * Root;
	bool First;
	
public :
	BSTree()
	{
		First = true;
	}
	
	void AddBSTreeNode(int Val)
	{
		if(First)
		{
			Root = new BSTreeNode(Val);
			First = false;
		}
		else
		{
			bool Check = true;
			BSTreeNode * Temp = Root; 

			while(1)
			{
				if(Temp->RetVal() > Val)
				{ 
					Check = false;
					if(Temp->RetLNodeAdd() != NULL)
						Temp = Temp->RetLNodeAdd();
					else
						break;
				}
				else
				{
					Check = true;
					if(Temp->RetRNodeAdd() != NULL)
						Temp = Temp->RetRNodeAdd();
					else
						break;
				}
				
			}
			
			BSTreeNode * Current;
			Current = Temp;
			Temp = new BSTreeNode(Val);
				
			if(Check)
				Current->SetRNodeAdd(Temp);
			else
				Current->SetLNodeAdd(Temp);
		}
	}
	
	void Traversal(TrType Type)
	{
		BSTreeNode * Temp = Root;
		
		switch (Type)
		{
			case PreOrder :
			{
				cout << endl << "PreOrder Traversal Result : ";
				PreOT(Temp);
				break;
			}
			case InOrder :
			{
				cout << endl << "InOrder Traversal Result : ";
				IOT(Temp);
				break;
			}
			case PostOrder :
			{
				cout << endl << "PostOrder Traversal Result : ";
				PostOT(Temp);
				break;
			}
		}
	}
	
	void PreOT(BSTreeNode * RootNode)
	{
		cout << "  " << RootNode->RetVal();
		
		if(RootNode->RetLNodeAdd() != NULL)
			PreOT(RootNode->RetLNodeAdd());
		
		if(RootNode->RetRNodeAdd() != NULL)
			PreOT(RootNode->RetRNodeAdd());
	}
	
	void IOT(BSTreeNode * RootNode)
	{
		if(RootNode->RetLNodeAdd() != NULL)
			IOT(RootNode->RetLNodeAdd());
		
		cout << "  " << RootNode->RetVal();
		
		if(RootNode->RetRNodeAdd() != NULL)
			IOT(RootNode->RetRNodeAdd());
		
	}
	
	void PostOT(BSTreeNode * RootNode)
	{
		if(RootNode->RetLNodeAdd() != NULL)
			PostOT(RootNode->RetLNodeAdd());
		
		if(RootNode->RetRNodeAdd() != NULL)
			PostOT(RootNode->RetRNodeAdd());
			
		cout << "  " << RootNode->RetVal();
	}
};

int main()
{
	BSTree Ob;
	int Val;
	char Ans = 'y';
	
	while(tolower(Ans) == 'y')
	{
		cout << "Enter the Value for Node : ";
		cin >> Val;
		Ob.AddBSTreeNode(Val);
		
		cout << "Do U want to Conitnue(Y/N) : ";
		cin >> Ans;
	}
	
	Ob.Traversal(PreOrder);
	Ob.Traversal(InOrder);
	Ob.Traversal(PostOrder);
	
	cout << endl;
	return 0;
} 