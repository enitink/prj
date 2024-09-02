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
    int maxScoreHelper(vector<vector<int>>& grid, set<int>& scores, int r, int c, int sr) {
        if ((scores.size() == r) || (sr >= r))
            return accumulate(scores.begin(), scores.end(), 0);
        int i=0, max = accumulate(scores.begin(), scores.end(), 0);
        bool entered = false;
        for(;i<c;++i) {
            if (scores.find(grid[sr][i]) == scores.end()) {
                scores.insert(grid[sr][i]);
                entered = true;
                int lmax = maxScoreHelper(grid, scores, r, c, sr+1);
                if (lmax > max)
                    max = lmax;
                scores.erase(grid[sr][i]);
            }
        }
        if ((!entered) && (sr < r-1)){
            int lmax = maxScoreHelper(grid, scores, r, c, sr+1);
                if (lmax > max)
                    max = lmax;
        }

        return max;
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        for(auto& g:grid) {
            sort(g.begin(), g.end(), greater<int>());
        }
        int r = grid.size();
        int c = grid[0].size();
        int i,j;
        set<int> scores;
        return maxScoreHelper(grid, scores, r, c, 0);
    }
};

int main() {
    Solution sol;
    {
        vector<vector<int>> grid = {{1, 2, 3}, {4, 3, 2}, {1, 1, 1}};
        cout<<sol.maxScore(grid)<<endl;
    }
    {
        vector<vector<int>> grid = {{8,7,6}, {8,3,2}};
        cout<<sol.maxScore(grid)<<endl;
    }
    {
        // [[5],[7],[19],[5]]
        vector<vector<int>> grid = {{5}, {7}, {19}, {5}};
        cout<<sol.maxScore(grid)<<endl;
    }
    {
        //[5,5],[5,5],[11,5]
        vector<vector<int>> grid = {{5,5}, {5,5}, {11,5}};
        cout<<sol.maxScore(grid)<<endl;
    }
    return 0;
}