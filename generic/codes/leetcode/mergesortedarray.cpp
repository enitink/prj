/**************************************SOLVED****************************************************
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers
m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 
Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

Solution Link : https://leetcode.com/submissions/detail/581493538/
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
private:
    int lowerbound(vector<int> &nums, int st, int end, int target)
    {
        if (end < st)
            return end + 1;
        int pos = -1;
        int mid = (st + end) / 2;
        if (target == nums[mid])
            return mid;
        else if (target < nums[mid])
            pos = lowerbound(nums, st, mid - 1, target);
        else
            pos = lowerbound(nums, mid + 1, end, target);

        return  pos;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        for ( ; i<n; ++i)
        {
            int pos = lowerbound(nums1, 0, m - 1, nums2[i]);
            if (pos >= m)
            {
                for( ;i<n; ++i)
                    nums1[pos++] = nums2[i];
                break;
            }
            else 
            {
                for(j=m-1; j>=pos; --j)
                    nums1[j+1] = nums1[j];
                nums1[pos] = nums2[i];
                ++m;
            }
        }
        return;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        ob.merge(nums1, 3, nums2, 3);
        printVector(nums1);
    }
    {
        vector<int> nums1 = {0};
        vector<int> nums2 = {1};
        ob.merge(nums1, 0, nums2, 1);
        printVector(nums1);
    }
    return 0;
}