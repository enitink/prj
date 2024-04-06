#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    int nums[50000];
    int size;

    int getLeftChildIndex(int parentIndex) { return (2 * parentIndex) + 1; }
    int getRightChildIndex(int parentIndex) { return (2 * parentIndex) + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    int getLeftChild(int parentIndex) { return nums[getLeftChildIndex(parentIndex)]; }
    int getRightChild(int parentIndex) { return nums[getRightChildIndex(parentIndex)]; }
    int getParent(int childIndex) { return nums[getParentIndex(childIndex)]; }

    bool isLeftChildPresent(int parentIndex) { return getLeftChildIndex(parentIndex) < size; }
    bool isRightChildPresent(int parentIndex) { return getRightChildIndex(parentIndex) < size; }
    bool isParentPresent(int index) { return getParentIndex(index) >= 0; }

    void swap(int& a, int& b) { int temp = a; a = b; b = temp; }

public:

    int getSize() { return size; }
    int peek() { return nums[0]; }

    Heap(): size(0) {}

    //removes node
    int* poll()
    {
        if (size == 0)
            return nullptr;
        int* result = new int;
        *result = nums[0];
        nums[0] = nums[size - 1];
        --size;
        heapifyDown();
        return result;
    }

    void insert(int val)
    {
        nums[size] = val;
        ++size;
        heapifyUp();
    }

    void heapifyDown()
    {
        int index = 0;
        while (isLeftChildPresent(index))
        {
            int childIndex = getLeftChildIndex(index);
            if (isRightChildPresent(index) && (nums[childIndex] < getRightChild(index)))
                childIndex = getRightChildIndex(index);

            if (nums[index] > nums[childIndex])
                break;
            else
            {
                swap(nums[index], nums[childIndex]);
            }
            index = childIndex;
        }
    }

    void heapifyUp()
    {
        int index = size - 1;
        while((isParentPresent(index)) && (getParent(index) < nums[index]))
        {
            int parentIndex = getParentIndex(index);
            swap(nums[index], nums[parentIndex]);
            index = parentIndex;
        }
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator eit = nums.end();
        Heap hp;
        for(; it != eit; ++it)
        {
            hp.insert(*it);
        }
        
        while(hp.getSize() > 1 )
        {
            int *mdata = hp.poll();
            int *smdata = hp.poll();
            int data = (*mdata) - (*smdata);
            if (data > 0)
            {
                hp.insert(data);
            }
            delete mdata;
            delete smdata;
        }

        int * data = hp.poll();
        int result = 0;
        if (data)
        {
            result =  *data;
            delete data;
        }
        return result;
    }
};

int main()
{
    Solution ob;
    int arr[6] = {2,7,4,1,8,1};
    vector<int> nums(arr, arr + 6);
    cout << ob.lastStoneWeight(nums) << endl;

    int arr1[1] = {1};
    vector<int> nums1(arr1, arr1 + 1);
    cout << ob.lastStoneWeight(nums1) << endl;
}