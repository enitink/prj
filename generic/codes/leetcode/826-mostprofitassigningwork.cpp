#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class DiffProfit {
public:
    DiffProfit(int d, int p) : diff(d), profit(p) {}
    int diff;
    int profit;
};

class Compare {
public:
    bool operator()(DiffProfit& a, DiffProfit& b)
    {
        if (a.diff == b.diff)
            return a.profit < b.profit;
        return a.diff > b.diff;
    }
};

bool Comp(const DiffProfit& a, const DiffProfit& b) {
    return a.diff < b.diff;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue< DiffProfit, vector<DiffProfit>, Compare > pq;
        int len = difficulty.size(), i = 0;
        for(;i<len;++i) {
            pq.push(DiffProfit(difficulty[i], profit[i]));
        }
        vector<DiffProfit> dpv;
        int max = 0;
        while(!pq.empty()) {
            DiffProfit dp = pq.top();
            pq.pop();
            if (dp.profit > max)
                max = dp.profit;
            else
                dp.profit = max;
            dpv.push_back(dp);
        }
        /*for (auto& d : dpv) {
            cout << d.diff << ":" << d.profit << " ";
        }*/
        cout << endl;
        max = 0;
        cout << endl;
        for (auto& w : worker) {
            DiffProfit dp(w,0);
            auto low = lower_bound(dpv.begin(), dpv.end(), dp, Comp);
            if (low == dpv.end())
                --low;
            if (low != dpv.end()) {
                if (low->diff > w) {
                    if (low != dpv.begin())
                        low--;
                    else
                        continue;
                }
                max += low->profit;
            }
        }
        return max;
    }
};

int main() {
    Solution s;

    /*{
        vector<int> difficulty = {2,4,6,8,10};
        vector<int> profit = {10,20,30,40,50};
        vector<int> worker = {4,5,6,7};
        cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    }
    {
        vector<int> difficulty = {85,47,57};
        vector<int> profit = {24,66,99};
        vector<int> worker = {40,25,25};
        cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    }
    {
        // 35,47,52,68,86
        // 17,81,81,81,81
        vector<int> difficulty = {68,35,52,47,86};
        vector<int> profit = {67,17,1,81,3};
        vector<int> worker = {92,10,85,84,82};
        cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    }
    {
        vector<int> difficulty = {68,35,52,47,86};
        vector<int> profit = {67,17,1,81,3};
        vector<int> worker = {92,10,85,84,82};
        cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    }*/
    {
        vector<int> difficulty = {23,30,35,35,43,46,47,81,83,98};
        vector<int> profit = {8,11,11,20,33,37,60,72,87,95};
        vector<int> worker = {95,46,47,97,11,35,99,56,41,92};
        cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    }
    return 0;
}