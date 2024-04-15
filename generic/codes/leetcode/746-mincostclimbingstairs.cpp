#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        return dp[n];
    }
};

int main()
{
    Solution sol;
    {
        vector<int> cost = {10, 15, 20};
        cout << sol.minCostClimbingStairs(cost) << endl;
    }
    {
        vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        cout << sol.minCostClimbingStairs(cost) << endl;
    }

    return 0;
}
