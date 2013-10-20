#include<stdio.h>

enum TrType {PreOrder, InOrder, PostOrder};
enum Boolean{false, true};

typedef struct
{
	struct TreeNode * LChild;
	int Data;
	struct TreeNode * RChild;
}TreeNode;

void AddBSTreeNode(struct TreeNode * Root, int Val, enum Boolean * First)
{
	if(First)
	{
		Root->LChild = NULL;
		Root->Data = Val
		Root->RChild = NULL;
		*First = false;
	}
	else
	{
		Boolean Check = true;
		struct TreeNode * Temp = Root; 

		while(1)
		{
			if(Temp->Data > Val)
			{ 
				Check = false;
				if(Temp->LChild != NULL)
					Temp = Temp->LChild;
				else
					break;
			}
			else
			{
				Check = true;
				if(Temp->RChild != NULL)
					Temp = Temp->RChild;
				else
					break;
			}
			
		}
		
		BSTreeNode * Current;
		Current = Temp;
		Temp->LChild = NULL;
		Temp->Data = Val
		Temp->RChild = NULL;
			
		if(Check)
			Current->RChild = Temp;
		else
			Current->LChild = Temp;
	}
}

void Traversal(TrType Type, struct TreeNode * Root)
{
	struct TreeNode * Temp = Root;
	
	switch (Type)
	{
		case PreOrder :
		{
			printf("\nPreOrder Traversal Result : ");
			PreOT(Temp);
			break;
		}
		case InOrder :
		{
			printf("\nInOrder Traversal Result : ");
			IOT(Temp);
			break;
		}
		case PostOrder :
		{
			printf("\nPostOrder Traversal Result : ");
			PostOT(Temp);
			break;
		}
	}
}

void PreOT(Struct TreeNode * RootNode)
{
	printf(" %d", RootNode->Data);
	
	if(RootNode->LChild != NULL)
		PreOT(RootNode->LChild);
	
	if(RootNode->RChild != NULL)
		PreOT(RootNode->RChild);
}

void IOT(Struct TreeNode * RootNode)
{
	if(RootNode->LChild == NULL)
		printf(" %d", RootNode->Data);
	else
	{
		IOT(RootNode->RChild);
		printf(" %d", RootNode->Data);
	}
	
	if(RootNode->RChild != NULL)
		IOT(RootNode->RChild);
	
}

void PostOT(Struct TreeNode * RootNode)
{
	if(RootNode->LChild != NULL)
		PreOT(RootNode->LChild);
	
	if(RootNode->RChild != NULL)
		PreOT(RootNode->RChild);
	
	printf(" %d", RootNode->Data);
}

int main()
{
	printf("\nProgram for Printing Binary Tree");
	struct TreeNode * Ob;
	int Val;
	char Ans = 'y';
	Boolean First = true; 
	
	while(tolower(Ans) == 'y')
	{
		printf("\nEnter the Value for Node : ");
		scanf("%d", &Val);
		AddBSTreeNode(Ob, Val, First);
		
		printf("\nDo U want to Conitnue(Y/N) : ");
		scanf("%d", &Ans);
	}
	
	Traversal(PreOrder, Ob);
	Traversal(InOrder, Ob);
	Traversal(PostOrder, Ob);
	
	printf("\n");
	return 0;
}