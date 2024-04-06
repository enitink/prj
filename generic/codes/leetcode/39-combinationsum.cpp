#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if ( (target < 0)  || (index >= candidates.size()) ) {
            return;
        }

        current.push_back(candidates[index]);
        helper(candidates, target - candidates[index], result, current, index);
        current.pop_back();
        helper(candidates, target, result, current, index + 1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        helper(candidates, target, result, current, 0);
        
        return result;
    }
};

void printvector(vector<vector<int>> vec)  {
    cout << "[";
    for (auto v : vec) {
        cout << "[";
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sol;
    {
        vector<int> candidates = {2, 3, 6, 7};
        int target = 7;
        vector<vector<int>> result = sol.combinationSum(candidates, target);
        printvector(result);
    }
    {
        vector<int> candidates = {2, 3, 5};
        int target = 8;
        vector<vector<int>> result = sol.combinationSum(candidates, target);
        printvector(result);
    }

    return 0;
}