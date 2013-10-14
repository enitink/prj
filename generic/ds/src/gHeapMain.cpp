#include <gHeap.h>
#include <iostream>

using namespace gen::ds::heap;

int main()
{
	int arr[10] = {4,6,2,0,8,3,1,9,5,7};
	gHeap <int> maxHeap(MAX_HEAP, arr, 10);
	gHeap <int> minHeap(MIN_HEAP, arr, 10);
	
	cout << endl << "descending order sort : ";
	while (maxHeap.empty())
	{
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}	
	cout << endl << "ascending order sort : ";	
	while (minHeap.empty())
	{
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	gHeap <int> iMaxHeap(MAX_HEAP);
	gHeap <int> iMinHeap(MIN_HEAP);
	for (int i = 0; i < 10; ++i)
	{
		iMaxHeap.insert(arr[i]);
		iMinHeap.insert(arr[i]);
	}
	cout << endl << "iMaxHeap : ";
	iMaxHeap.print();
	cout << "iMinHeap : ";
	iMinHeap.print();
	cout << "descending order sort : ";
	while (iMaxHeap.empty())
	{
		cout << iMaxHeap.top() << " ";
		iMaxHeap.pop();
	}
	cout << endl << "ascending order sort : ";
	while (iMinHeap.empty())
	{
		cout << iMinHeap.top() << " ";
		iMinHeap.pop();
	}
	cout << endl;
	return 0;
}
