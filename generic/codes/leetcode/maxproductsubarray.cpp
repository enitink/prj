/*************************************************************************************************
152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
It is guaranteed that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.
 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*************************************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>::const_iterator iter = nums.begin();
        vector<int>::const_iterator eiter = nums.end();
        int lproduct = *iter;
        int result = *iter;
        ++iter;
        for ( ; iter != eiter; ++iter)
        {
            lproduct *= (*iter);
            result = (result < lproduct) ? result : lproduct;
        }
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {2,3,-2,4};
        int i = 0;
        vector<int> nums;
        for( ; i<4; ++i)
            nums.push_back(arr[i]);
        cout << ob.maxProduct(nums) << endl;
    }
}