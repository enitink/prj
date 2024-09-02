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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        while(k--) {
            auto [val, idx] = pq.top();
            pq.pop();
            pq.push({val*multiplier, idx});
        }
        vector<int> result(nums.size(), 0);
        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            result[idx] = val;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,1,3,5,6};
    vector<int> result = s.getFinalState(nums, 5, 2);
    for(auto& x: result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}