/********************************SOLVED********************************************************
167. Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number. Let these two numbers
be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        result.resize(2);

        int nsize = numbers.size();
        int i = 0;
        
        for( ; i < nsize; ++i)
        {
            int req = target - numbers[i];
            int pos = binarysearch(numbers, 0, nsize - 1, req);
            if (-1 != pos)
            {
                if (pos == i)
                {
                    if (numbers[pos+1] != numbers[pos])
                    {
                        continue;
                    }
                    pos = pos + 1;
                }
                result[0] = i+1;
                result[1] = pos+1;
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {2,4,4,6,15};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.twoSum(nums, 8);
        printVector(result);
    }
    {
        int maxarr[] = {2,3,4};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.twoSum(nums, 6);
        printVector(result);
    }
    {
        int maxarr[] = {-1,0};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        vector<int> result = ob.twoSum(nums, -1);
        printVector(result);
    }
    return 0;
}