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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res;
        priority_queue<int> maxHeap;

        for (auto& q : queries) {
            int d = abs(q[0]) + abs(q[1]);
            if (maxHeap.size() < k) {
                maxHeap.push(d);
            } else if (d < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(d);
            }
            if (maxHeap.size() == k) {
                res.push_back(maxHeap.top());
            } else
                res.push_back(-1);
        }

        return res;
    }
};

int main() {
    Solution sol;
    {
        vector<vector<int>> queries = {{1, 2}, {3, 4}, {2, 3}, {-3,0}};
        int k = 2;
        vector<int> res = sol.resultsArray(queries, k);
        for(auto r:res){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    {
        vector<vector<int>> queries = {{5, 5}, {4, 4}, {3, 3}};
        int k = 1;
        vector<int> res = sol.resultsArray(queries, k);
        for(auto r:res){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}