/**************************************************************************************************
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order
of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done? 
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

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int begzero = -1;
        int i = 0;
        int lnums = nums.size();
        for( ;i<lnums;++i)
        {
            if (!nums[i])
            {
                if ((-1 == begzero) || (begzero > i))
                    begzero = i;
            }
            else 
            {
                if (-1 == begzero)
                    continue;
                nums[begzero] = nums[i];
                nums[i] = 0;
                begzero++;
                for( ; begzero<i; ++begzero)
                {
                    if (!nums[begzero])
                        break;
                }
            }   
        }
        return;
   }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {0,1,0,3,12};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {0,1,0,3,0};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {0,0,0,0,12};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {1,0,0,0,12};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {0,0,1,0,12};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {0,0,1,0,0};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {0};
        int i = 0;
        vector<int> nums;
        for (; i < 1; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {1};
        int i = 0;
        vector<int> nums;
        for (; i < 1; ++i)
            nums.push_back(maxarr[i]);
        ob.moveZeroes(nums);
        printVector(nums);
    }
    return 0;
}