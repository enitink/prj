#include <stdio.h>
#include <malloc.h>

#define null 0

struct Node
{
	int value;
	struct Node* next;
};

void addData(int data, struct Node* pHead)
{
	struct Node* pTemp = (struct Node*) malloc(sizeof(struct Node));
	struct Node* pLocTemp;
	pTemp->value = data;
	pTemp->next = null;
	
	if (pHead == null)
	{
		pHead = pTemp;
	}
	else
	{
		pLocTemp = pHead;
		while (pLocTemp->next)
		{
			pLocTemp = pLocTemp->next;
		}
		pLocTemp->next = pTemp;
	}
}

void deleteData(struct Node* pHead, int delData)
{
	struct Node* pLocTemp = pHead;

	if(pHead == null)
	{
		printf("Nothing to delete");
		return;
	}
	if (!pLocTemp->next)
	{
		if (pLocTemp->value == delData)
		{
			free(pLocTemp);
			*pHead = null;
			return;
		}
	}
	else
	{
		while (pLocTemp->next)
		{
			if (pLocTemp->next->value == delData)
			{
				free(pLocTemp);
				pLocTemp->next = null;
				return;
			}
			pLocTemp = pLocTemp->next;
		}	
	}
	printf("Data not found");
	return;
}

void print(struct Node* pHead)
{
	while(pHead)
	{
		printf("%d ", pHead->value);
		pHead = pHead->next;
	}
}

int main()
{
	struct Node* pHead = null;
	int i;
	for(i = 0; i < 10; ++i)
		addData(pHead, i);
	printf("\n");
	print(pHead);
	deleteData(pHead, 5);
	deleteData(pHead, 10);
	deleteData(pHead, 0);
	print(pHead);
	return 0;
}
