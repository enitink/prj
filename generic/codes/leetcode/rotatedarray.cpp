/**************************************************************************************************
189. Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 10^5
-231 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
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
    // This one worked, but more space taken
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> result(nums.end()-k, nums.end());
        nums.erase(nums.end()-k, nums.end());
        nums.insert(nums.begin(), result.begin(), result.end());
    }
    // Below one time limit exceeded.
    /* void rotate(vector<int>& nums, int k) {
        int lnums = nums.size();
        int mid = lnums / 2;
        int i = 0;
        k = k % lnums;
        if (mid < k)
        {
            for ( ; i< lnums - k; ++i)
            {
                vector<int>::iterator itr = nums.begin();
                int num = *itr;
                nums.erase(itr);
                nums.push_back(num);
            }
        }
        else
        {
            for ( ; i<k; ++i)
            {
                vector<int>::iterator itr = nums.end() - 1;
                int num = *itr;
                nums.erase(itr);
                nums.insert(nums.begin(), num);
            }
        }
        return;
    } */
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 3);
        printVector(nums);
    }
    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 4);
        printVector(nums);
    }
    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 5);
        printVector(nums);
    }
    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 1);
        printVector(nums);
    }
    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 10);
        printVector(nums);
    }
    {
        int maxarr[] = {1,2,3,4,5,6,7};
        int i = 0;
        vector<int> nums;
        for (; i < 7; ++i)
            nums.push_back(maxarr[i]);
        ob.rotate(nums, 7);
        printVector(nums);
    }
    return 0;
}