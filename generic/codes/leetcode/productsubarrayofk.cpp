/**************************************************************************************************

713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays where 
the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& vec)
{
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator eiter = vec.end();

    cout << "[";
    for ( ; iter != eiter; ++iter)
    {
        if (iter != vec.begin())
            cout << ",";
        cout << *iter;
    }
    cout << "]" << endl;

}

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        vector<int>::const_iterator iter = nums.begin();
        vector<int>::const_iterator eiter = nums.end();
        vector<int> products;

        int result = 0;

        for ( ; iter != eiter; ++iter)
        {
            vector<int>::iterator liter = products.begin();
            vector<int>::iterator leiter = products.end();

            for ( ; liter != leiter; ++liter)
            {
                (*liter) = (((*liter) * (*iter)) > 10000) ? 10000 : ((*liter) * (*iter));
                if (*liter < k)
                    ++result;
            }
            if (*iter < k)
                ++result;
            products.push_back(*iter);
        }

        return result;
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {10,5,2,6};
        int i = 0;
        vector<int> nums;
        for( ; i<4; ++i)
            nums.push_back(arr[i]);
        cout << ob.numSubarrayProductLessThanK(nums, 100) << endl;
    }
    {
        int arr[] = {1,2,3};
        int i = 0;
        vector<int> nums;
        for( ; i<3; ++i)
            nums.push_back(arr[i]);
        cout << ob.numSubarrayProductLessThanK(nums, 0) << endl;
    }
    {
        int arr[] = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
        int i = 0;
        vector<int> nums;
        for( ; i<14; ++i)
            nums.push_back(arr[i]);
        cout << ob.numSubarrayProductLessThanK(nums, 19) << endl;
    }
    {
        int arr[] = {10,2,2,5,4,4,4,3,7,7};
        int i = 0;
        vector<int> nums;
        for( ; i<14; ++i)
            nums.push_back(arr[i]);
        cout << ob.numSubarrayProductLessThanK(nums,289) << endl;
    }
    return 0;
}