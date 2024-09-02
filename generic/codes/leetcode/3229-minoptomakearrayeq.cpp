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
        int len = target.size();
        int result = 0, i, diff, incr = 0, decr = 0;
        for (i = 0; i < len; ++i) {
            diff = target[i] - nums[i];
            //cout << diff << ":" << incr << ":" << decr << endl;
            if (diff > 0) {
                if (diff > incr) {
                    result += (diff - incr);
                }
                incr = diff;
                decr = 0;
            } else if (diff < 0) {
                if (abs(diff) > decr) {
                    result += (abs(diff) - decr);
                }
                decr = abs(diff);
                incr = 0;
            } else {
                incr = decr = 0;
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