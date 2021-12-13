/**************************************************************************************************
350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in
the result must appear as many times as it shows in both arrays and you may return the result
in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


Solution Link : https://leetcode.com/submissions/detail/581498382/
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int arr[1001] = {0};
        vector<int> result;
        vector<int>::const_iterator iter = nums1.begin();
        vector<int>::const_iterator eiter = nums1.end();
        for( ; iter != eiter; ++iter)
            arr[*iter]++;
        iter = nums2.begin();
        eiter = nums2.end();
        for( ; iter != eiter; ++iter)
        {
            if ((arr[*iter]--) > 0)
            {
                result.push_back(*iter);
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        vector<int> nums1 = {1,2,2,1};
        vector<int> nums2 = {2,2};
        vector<int> result = ob.intersect(nums1, nums2);
        printVector(result);
    }
    {
        vector<int> nums1 = {9,4,9,8,4};
        vector<int> nums2 = {4,9,5,8};
        vector<int> result = ob.intersect(nums1, nums2);
        printVector(result);
    }
    return 0;
}