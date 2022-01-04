/*******************************************************************************
153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element
of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        cout << endl << start << " : " << end;
        if (end < start)
            return nums[end + 1];
 
        int mid = (start + end) / 2;

        int pos = 0;
        //if mid is greater then start then it's sorted part, min will be in
        //unsorted array look into it
        if (nums[start] > nums[mid])
        {
            pos =  binarySearch(nums, target, start, mid - 1);
        }
        else
        {
            pos = binarySearch(nums, target, mid + 1, end);
        }
        
        return pos;
    }

public:
    int findMin(vector<int> &nums)
    {
        int val =  binarySearch(nums, -5001, 0, nums.size() - 1);
        cout << endl;
        return val;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums = {13, 14, 15, 16, 17, 18, 19, 20, 21, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12};
        cout  << ob.findMin(nums) << endl;
    }
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        //cout << ob.findMin(nums) << endl;
    }
    {
        vector<int> nums = {1};
       // cout << ob.findMin(nums) << endl;
    }
}