#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans += mx;
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    {
        vector<int> nums = {1,3,1,5};
        cout << s.findMaximumScore(nums) << endl;
    }
    {
        vector<int> nums = {4,3,1,3,2};
        cout << s.findMaximumScore(nums) << endl;
    }
    {
        vector<int> nums = {1,3,7,10};
        cout << s.findMaximumScore(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3};
        cout << s.findMaximumScore(nums) << endl;
    }
    {
        // 4,5,3
        vector<int> nums = {4,5,3};
        cout << s.findMaximumScore(nums) << endl;
    }
    return 0;
}
