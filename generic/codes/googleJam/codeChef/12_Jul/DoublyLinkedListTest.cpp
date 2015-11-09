#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main()
{
	DoublyLinkedListT <int> obj;
	
	for (int i = 0; i < 10; ++i)
		obj.AddNodeAtEnd(i);

	DoublyLinkedListNodeT <int> *pObj = obj.GetHead();

	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	obj.MoveHead(5);
	pObj = obj.GetHead();
	
	cout << endl;
	for (int i = 0; i < 10 && pObj != null; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	obj.MoveHead(8, false);
	obj.DeleteNodeFromFront();
	obj.DeleteNodeFromEnd();
	obj.DeleteNodeFromFront();
	obj.DeleteNodeFromEnd();
	obj.AddNodeAtEnd(100);
	obj.AddNodeAtFront(-100);
	obj.AddNodeAtEnd(200);
	pObj = obj.GetHead();
	cout << endl;
	for (int i = 0; i < 10 && pObj != null; ++i)
	{
		cout << " " << pObj->GetData();
		pObj = pObj->GetNextNode();
	}

	return 0;
}
