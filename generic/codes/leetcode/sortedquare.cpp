/********************************SOLVED****************************************
977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares
of each number sorted in non-decreasing order. 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n)
solution using a different approach?
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
    vector<int> sortedSquares(vector<int>& nums) {
        int sz=nums.size() - 1;
        vector<int> result;
        int num;
        for ( ; sz > 0;  --sz)
        {
            if (nums[sz] < 0)
                break;
            num = nums[sz] * nums[sz];
            result.insert(result.begin(), num);
        }
        int i = 0;
        for( ; i<=sz; ++i)
        {
            num = nums[i] * nums[i];
            int pos = lowerbound(result, 0, result.size() - 1, num);
            result.insert(result.begin()+pos, num);
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {-4,-1,0,3,10};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.sortedSquares(nums);
        printVector(result);
    }
    {
        int maxarr[] = {-7,-3,2,3,11};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.sortedSquares(nums);
        printVector(result);
    }
    {
        int maxarr[] = {-7,-6,-5,-4,-3};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.sortedSquares(nums);
        printVector(result);
    }
    {
        int maxarr[] = {1,2,3,4,5};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.sortedSquares(nums);
        printVector(result);
    }
    return 0;
}