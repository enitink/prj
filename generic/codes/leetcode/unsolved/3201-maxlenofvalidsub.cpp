#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    int helper(vector<int>& nums, int index, int count, int rem) {
        if (index == nums.size()) {
            return count;
        }
        int i;
        int max = 0;
        for (i = index + 1; i < nums.size(); ++i) {
            if (((nums[index] + nums[i]) % 2) == rem) {
                int lmax = helper(nums, i, count + 1, rem);
                if (lmax > max)
                    max = lmax;
            }
        }
        int lmax = helper(nums, index + 1, count, rem);
        if (lmax > max)
            max = lmax;
        return max;
    }

public:
    int maximumLength(vector<int>& nums) {
        int result = helper(nums, 0, 0, 0);
        int lresult = helper(nums, 0, 0, 1);
        return result > lresult ? result : lresult;
    }
};

int main() {
    Solution s;
    
    vector<int> v1 = {1, 2, 3, 4};
    cout << s.maximumLength(v1) << endl;
    
    return 0;
}