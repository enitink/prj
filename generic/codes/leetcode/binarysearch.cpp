/************************************SOLVED********************************************************
 * 704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order
**************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarysearch(vector<int>& nums, int st, int end, int target)
    {
        if (end < st)
            return -1;
        int pos = -1;
        int mid = (st+end)/2;
        if ( target == nums[mid])
            return mid;
        else if (target < nums[mid])
            pos = binarysearch(nums, st, mid - 1, target);
        else
            pos = binarysearch(nums, mid + 1, end, target);

        return pos;
    }

    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size() - 1, target );
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 14) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 2) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, -1) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 0) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 3) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 5) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 9) << endl;
    }
    {
        int maxarr[] = {-1,0,3,5,9,12};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.search(nums, 12) << endl;
    }
}