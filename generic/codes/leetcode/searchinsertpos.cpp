/************************************SOLVED*************************************
 * 35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int binarysearch(vector<int> &nums, int st, int end, int target)
    {
        if (end < st)
            return end + 1;
        int pos = -1;
        int mid = (st + end) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            pos = binarysearch(nums, st, mid - 1, target);
        else
            pos = binarysearch(nums, mid + 1, end, target);

        
        return  pos;
    }
    int searchInsert(vector<int> &nums, int target)
    {
        return binarysearch(nums, 0, nums.size() - 1, target);
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 0) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 2) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 4) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
        int i = 0;
        vector<int> nums;
        for (; i < 11; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 6) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 8) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 1) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 3) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 5) << endl;
    }
    {
        int maxarr[] = {1, 3, 5, 6};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.searchInsert(nums, 6) << endl;
    }
    return 0;
}