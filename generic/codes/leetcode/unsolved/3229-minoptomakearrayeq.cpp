#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>
#include <limits>
#include <iterator>
#include <memory>
#include <array>

using namespace std;

class Solution {

public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int len = target.size(),i;
        vector<int> diffs(len);
        for (i = 0; i < len; ++i) {
            diffs[i]= (target[i] - nums[i]);
        }
        int result = 0;
        i = 0;
        int prevdiff = diffs[i];
        int lmax = diffs[i];
        for(i=0;i<len-1;++i) {
            if (prevdiff == diffs[i]) {
                continue;
            }
            else {
                prevdiff = diffs[i];
                if (lmax < diffs[i]) {
                    lmax = diffs[i];
                }
                result += abs(lmax);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {3,5,1,2};
        vector<int> target = {4,6,2,4};
        cout << sol.minimumOperations(nums, target) << endl;
    }
    {
        vector<int> nums = {3,2,1,5,3};
        vector<int> target = {4,4,2,6,5};
        cout << sol.minimumOperations(nums, target) << endl;
    }
    {
        vector<int> nums = {1,2,3,4,5};
        vector<int> target = {5,4,3,2,1};
        cout << sol.minimumOperations(nums, target) << endl;
    }
    {
        vector<int> nums = {1,1,1,1,1};
        vector<int> target = {1,1,1,1,1};
        cout << sol.minimumOperations(nums, target) << endl;
    }
    {
        vector<int> nums = {1,3,2};
        vector<int> target = {2,1,4};
        cout << sol.minimumOperations(nums, target) << endl;
    }
    return 0;
}