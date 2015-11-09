#include <iostream>
#include "doublyLinkedList.cpp"

using namespace std;

int main()
{
	CircularLinkedListT <int> obj;
	
	for (int i = 0; i < 10; ++i)
		obj.AddNode(i);

	CircularLinkedListNodeT <int> *pObj = obj.GetHead();

	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	obj.MoveHead(5);
	pObj = obj.GetHead();
	
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	obj.MoveHead(8, false);
	pObj = obj.GetHead();
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	return 0;
}
