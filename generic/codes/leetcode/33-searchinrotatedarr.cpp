#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    private:
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        if (end < start)
            return -1;
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[start] <= nums[mid]
             && target <= nums[mid]
             && target >= nums[start])
        {
            return binarySearch(nums,target,  start, mid - 1);
        }

        else if (nums[mid] <= nums[end]
                 && target >= nums[mid]
                 && target <= nums[end])
        {
            return binarySearch(nums, target, mid + 1, end);
        }

        else if (nums[end] <= nums[mid])
        {
            return binarySearch(nums, target, mid + 1, end);
        }

        else if (nums[start] >= nums[mid])
        {
            return binarySearch(nums,target, start, mid - 1);
        }

        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;

    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        cout << sol.search(nums, 0) << endl;
    }
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        cout << sol.search(nums, 3) << endl;
    }
    {
        vector<int> nums = {1};
        cout << sol.search(nums, 0) << endl;
    }
    {
        vector<int> nums = {1};
        cout << sol.search(nums, 1) << endl;
    }
    {
        vector<int> nums = {1, 3};
        cout << sol.search(nums, 3) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 3) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 1) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 0) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 2) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 4) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 5) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 6) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 7) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 8) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 9) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 10) << endl;
    }
    {
        vector<int> nums = {3, 1};
        cout << sol.search(nums, 11) << endl;
    }
    return 0;
}