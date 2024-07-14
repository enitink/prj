#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct _cuts {
    int cost;
    bool vert;
    _cuts(int c, bool v) : cost(c) , vert(v) {}
} cuts;

class Compare {
public:
    bool operator()(cuts below, cuts above){
        return below.cost < above.cost;
    }
};

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<cuts, vector<cuts>, Compare> pq;
        for(auto& h: horizontalCut) {
            pq.push(cuts(h, false));
        }
        for(auto& v: verticalCut) {
            pq.push(cuts(v, true));
        }
        int result = 0;
        int h=0, v=0;
        while(!pq.empty()) {
            cout << pq.top().cost << " " << pq.top().vert << endl;
            if(pq.top().vert) {
                ++v;
                result += (pq.top().cost * (h+1));

            } else {
                ++h;
                result += (pq.top().cost * (v+1));
            }
            pq.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        vector<int> h = {1,3};
        vector<int> v = {5};
        cout << s.minimumCost(3, 2, h, v) << endl;
    }
    return 0;
}