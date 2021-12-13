/*************************************SOLVED*******************************************************
152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the
largest product, and return the product.
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

**************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>::const_iterator iter = nums.begin();
        vector<int>::const_iterator eiter = nums.end();
        int result = *iter;
        ++iter;
        vector<int> products;
        products.push_back(result);

        for ( ; iter != eiter; ++iter)
        {
            vector<int>::iterator liter = products.begin();
            vector<int>::iterator leiter = products.end();

            for ( ; liter != leiter; ++liter)
            {
                (*liter) *= *iter;
                result = (result < (*liter)) ? (*liter) : result;
            }

            result = (result < (*iter)) ? (*iter) : result;
            products.push_back(*iter);
        }
        return result;
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
    {
        int arr[] = {-2,0,-1};
        int i = 0;
        vector<int> nums;
        for( ; i<3; ++i)
            nums.push_back(arr[i]);
        cout << ob.maxProduct(nums) << endl;
    }
    {
        int arr[] = {2,3,-2,4,-1};
        int i = 0;
        vector<int> nums;
        for( ; i<5; ++i)
            nums.push_back(arr[i]);
        cout << ob.maxProduct(nums) << endl;
    }
}