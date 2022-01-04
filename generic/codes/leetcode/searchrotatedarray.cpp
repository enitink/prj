/*******************************************************************************
33. Search in Rotated Sorted numsay

There is an integer numsay nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting numsay is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the numsay nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending numsay that is possibly rotated.
-104 <= target <= 104

Solution: - One of the half will be sorted.
            If the target doesn't belongs in the any of the sorted half.
            Then it will belong in the unsorted half.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        if (end < start)
            return -1;
        //int mid = start + (end - start) / 2;
        int mid = (start + end) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[start] <= nums[mid]
             && target <= nums[mid]
             && target >= nums[start])
        {
            return binarySearch(nums,target,  start, mid - 1);
        }

        else if (nums[mid] <= nums[end]
                 && target >= nums[mid]
                 && target <= nums[end])
        {
            return binarySearch(nums, target, mid + 1, end);
        }

        else if (nums[end] <= nums[mid])
        {
            return binarySearch(nums, target, mid + 1, end);
        }

        else if (nums[start] >= nums[mid])
        {
            return binarySearch(nums,target, start, mid - 1);
        }

        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
    Solution ob;
    {
        vector<int> nums = {1,0,1,1,1};
        cout << ob.search(nums, 0) << endl;
    }
    {
        vector<int> nums = {13, 14, 15, 16, 17, 18, 19, 20, 21, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12};
        cout << ob.search(nums, 14) << endl;
    }
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        cout << ob.search(nums, 4) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 5) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 6) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 7) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 0) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 1) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 2) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << ob.search(nums, 3) << endl;
    }
    {
        vector<int> nums = {1};
        cout << ob.search(nums, 0) << endl;
    }
}