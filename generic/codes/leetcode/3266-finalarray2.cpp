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


using namespace std;



class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        for(int i=0; i<nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        k = nums.size() % (k + 1);
        cout << k << endl;
        while(k--) {
            auto [val, idx] = pq.top();
            pq.pop();
            pq.push({val*multiplier, idx});
        }
        vector<int> result(nums.size(), 0);
        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            result[idx] = val % 1000000007;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100000,2000};
    vector<int> result = s.getFinalState(nums, 1000000000, 1000000);
    for(auto& x: result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}