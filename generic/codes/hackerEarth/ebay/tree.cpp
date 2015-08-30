#include <cstdio>
#include <cstring>

#define SIZE 20000

struct node
{
	int data;
	int parent;
};

typedef struct node treeNode_s;

int getInsertPos(treeNode_s arr[], int key, int beg,int end)
{
	while ((arr[beg].data <= key) && (beg < end))
	{
		++beg;
	}
	return beg;
}

bool searchBinKey(int& key, treeNode_s arr[], int beg, int end)
{
    int mid;
	while (beg <= end)
	{
		mid = (beg+end)/2;
        if(arr[mid].data == key)
        {  key = arr[mid].parent; return true; }
        else if(key < arr[mid].data)
            end = mid - 1;
        else
            beg = mid + 1;
	}
	return false;
}

int getAncestorsList(int key, treeNode_s dataArr[], int arr[], int size)
{
	int searchKey = key;
	int count = 0;
	arr[count] = searchKey;
 	while ( searchBinKey(searchKey, dataArr, 0, size - 1) )
	{
		arr[++count] = searchKey;
	}
	return count;
}

int main()
{
	treeNode_s arr[SIZE];
	int ansList[SIZE];
	memset(arr,0, sizeof(arr)); 
	int N,K,S,D, count, pos, res;

	scanf("%d%d", &N,&K);
	res = 0;
	count = 0;
	N--;
	while (N--)
	{
		scanf("%d%d",&S,&D);
		pos = getInsertPos(arr, D, 0, count);
		memmove(arr+pos+1, arr+pos, (count - pos) * sizeof(treeNode_s));
		arr[pos].data = D;
		arr[pos].parent = S;
		++count;
	}
	count--;


	for (int i = 0; i <= count; ++i)
	{
		int listCount = getAncestorsList(arr[i].parent, arr, ansList, count);
		for (int j = 0; j <= listCount; ++j)
		{
			if ( arr[i].data * ansList[j] <= K )
				++res;
		}
	}
	printf("%d",res);
	return 0;
}
