/**********************************SOLVED**********************************************************
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which
has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide
and conquer approach, which is more subtle.
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto itr = nums.begin();
        auto eitr = nums.end();
        int result = *itr;
        int lsum = *itr;
        ++itr;
        for( ; itr!=eitr; ++itr)
        {
            lsum += *itr;
            lsum = (lsum < *itr) ?  *itr : lsum;
            if (lsum > result)
                result = lsum;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        cout << endl << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {-1,-2,-3,-4,-5,-6,-7,-8,-9};
        cout << endl << ob.maxSubArray(nums);
    }
    {
        vector<int> nums = {-1,-2,-3,-4,5,-6,-7,-8,-9};
        cout << endl << ob.maxSubArray(nums);
    }
    return 0;
}