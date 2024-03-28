/**********************************SOLVED**********************************************************
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int lowerbound(vector<int>& nums, int st, int end, int target)
    {
        if (end < st)
            return end+1;
        int pos = -1;
        int mid = (st+end)/2;
        if ( target == nums[mid])
            return mid;
        else if (target < nums[mid])
            pos = lowerbound(nums, st, mid - 1, target);
        else
            pos = lowerbound(nums, mid + 1, end, target);

        return pos;
    }

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
public:

    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        vector<int>::iterator eiter = nums.end();

        vector<int> lnums;
        lnums.push_back(*iter);
        ++iter;
        for ( ; iter != eiter; ++iter)
        {
            if (-1 != binarysearch(lnums, 0, lnums.size()-1, *iter))
            {
                return true;
            }
            else 
            {
                int pos = lowerbound(lnums,0, lnums.size()-1, *iter);
                lnums.insert(lnums.begin()+pos, *iter);
            }
        }
        return false;
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {1,2,3,1};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.containsDuplicate(nums) << endl;
    }
    {
        int maxarr[] = {1,2,3,4};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.containsDuplicate(nums) << endl;
    }
    {
        int maxarr[] = {1,1,1,3};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.containsDuplicate(nums) << endl;
    }

    return 0;
}