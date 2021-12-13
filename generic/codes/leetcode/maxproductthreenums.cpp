/**************************************************************************************************
628. Maximum Product of Three Numbers

Given an integer maxarray nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        return 0;
    }
    /*int maximumProduct(vector<int> &nums)
    {
        int maxarr[3] = {-1001, -1001, -1001};
        int minarr[3] = {1001, 1001, 1001};

        vector<int>::const_iterator iter = nums.begin();
        vector<int>::const_iterator eiter = nums.end();
        int negcount = 0;

        for (; iter != eiter; ++iter)
        {
            if (*iter < 0)
                ++negcount;
            if (*iter > maxarr[0])
            {
                maxarr[0] = *iter;
                if (maxarr[0] > maxarr[1])
                {
                    int temp = maxarr[0];
                    maxarr[0] = maxarr[1];
                    maxarr[1] = temp;

                    if (maxarr[1] > maxarr[2])
                    {
                        int temp = maxarr[1];
                        maxarr[1] = maxarr[2];
                        maxarr[2] = temp;
                    }
                }
            }
            if (*iter < minarr[0])
            {
                minarr[0] = *iter;
                if (minarr[0] < minarr[1])
                {
                    int temp = minarr[0];
                    minarr[0] = minarr[1];
                    minarr[1] = temp;

                    if (minarr[1] < minarr[2])
                    {
                        int temp = minarr[1];
                        minarr[1] = minarr[2];
                        minarr[2] = temp;
                    }
                }
            }
        }
        cout << " " << maxarr[0] << " " << maxarr[1] << " " << maxarr[2] << endl;

        if (negcount >= 2)
        {
            if ((minarr[1] * minarr[2]) > (maxarr[0] * maxarr[1]))
            {
                maxarr[0] = minarr[1];
                maxarr[1] = minarr[2];
            }
        }

        cout << " " << minarr[0] << " " << minarr[1] << " " << minarr[2] << endl;
        cout << " " << maxarr[0] << " " << maxarr[1] << " " << maxarr[2] << endl;

        return (maxarr[0] * maxarr[1] * maxarr[2]);
    }*/
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {1, 2, 3};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {1, 2, 3, 4};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {-1, -2, -3};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
        int i = 0;
        vector<int> nums;
        for (; i < 10; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {1, -100, -98, 2, 3, 4};
        int i = 0;
        vector<int> nums;
        for (; i < 6; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {-1, -2, 1, 2, 3};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    {
        int maxarr[] = {-1,-2,-3,-4};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.maximumProduct(nums) << endl;
    }
    return 0;
}