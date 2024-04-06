#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int>& nums, int pos, vector<int>& result, vector<vector<int>>& results)
    {
        if (nums.size() == result.size())
        {
            results.push_back(result);
            return;
        }
        int rsize = result.size() + 1;
        for (int i = 0; i < rsize; ++i)
        {
            result.insert(result.begin() + i, nums[pos]);
            helper(nums, pos + 1, result, results);
            result.erase(result.begin() + i);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        int n = nums.size();
        vector<int> result;

        helper(nums, 0, result, results);

        return results;        
    }
};

void printvector(vector<vector<int>>& nums)
{
    cout << "[";
    for (auto& r : nums)
    {
        cout << "[";
        for (auto& i : r)
        {
            cout << i << " ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    
    {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result = s.permute(nums);
        printvector(result);
    }
    {
        vector<int> nums = {0, 1};
        vector<vector<int>> result = s.permute(nums);
        printvector(result);
    }
    {
        vector<int> nums = {1};
        vector<vector<int>> result = s.permute(nums);
        printvector(result);
    }
    {
        vector<int> nums = {1, 2, 3, 4};
        vector<vector<int>> result = s.permute(nums);
        printvector(result);
    }
    return 0;
}