/**********************************SOLVED***************************************
300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing
subsequence.

A subsequence is a sequence that can be derived from an array by deleting some
or no elements without changing the order of the remaining elements. For example,
[3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
complexity?
*******************************************************************************/
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
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> resultsvec;
        int numsize = nums.size();
        resultsvec.resize(numsize);
        int result = 0;
        int i = 0;

        for ( ; i<numsize; ++i)
        {
            int pos = i - 1;
            int lpos = -1;
            while (pos >= 0)
            {
                if (nums[pos] < nums[i])
                {
                    if ((lpos == -1) || (resultsvec[pos] > resultsvec[lpos]))
                            lpos = pos;
                }
                --pos;
            }
            resultsvec[i] = 1;
            if (lpos >= 0)
            {
                resultsvec[i] += resultsvec[lpos];
            }
            result = (result > resultsvec[i]) ? result : resultsvec[i];
        }
        return result;
    }
};

int main()
{
    Solution ob;
    {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        cout << ob.lengthOfLIS(nums) << endl;
    }
    {
        vector<int> nums = {0,1,0,3,2,3};
        cout << ob.lengthOfLIS(nums) << endl;
    }
    {
        vector<int> nums = {7,7,7,7,7};
        cout << ob.lengthOfLIS(nums) << endl;
    }
    return 0;
}