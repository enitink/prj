/**************************************************************************************************
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

Solution : Using permcombination, try to judge which number Kth position it belongs
to, then find out K+1, but catch is the numbers is not unique so it can't follow the same.

The solution which worked : https://redquark.org/leetcode/0031-next-permutation/
**************************************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsize = nums.size();
        int i = numsize - 1;
        int index = -1;
        for ( ; i>0; --i)
        {
            if (nums[i] > nums[i-1])
            {
                index = i - 1;
            }
        }
        int pos = 0;
        if (-1 != index )
        {
            i = numsize - 1;
            for ( ; i>0; --i)
            {
                if (nums[i] > nums[index])
                {
                    pos = i;
                    int temp = nums[i];
                    nums[i] = nums[pos];
                    nums[pos] = temp;
                }
            }
        }
        
        cout << index;
        sort(nums.begin() + (index + 1), nums.end());
    }
};

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

int main()
{
    Solution ob;

    {
        int maxarr[] = {1,2,3};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        ob.nextPermutation(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {3,2,1};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        ob.nextPermutation(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {1,1,5};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        ob.nextPermutation(nums);
        printVector(nums);
    }
    {
        int maxarr[] = {1};
        int i = 0;
        vector<int> nums;
        for (; i < 1; ++i)
            nums.push_back(maxarr[i]);
        ob.nextPermutation(nums);
        printVector(nums);
    }
    return 0;
}

