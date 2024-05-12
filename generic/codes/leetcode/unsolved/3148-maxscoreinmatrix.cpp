#include <iostream>
#include <vector>

using namespace std;

class Solution {
int helper(vector<vector<int>>& grid, int r, int c, int rt, int ct, int& rval, )
{
    int max = INT_MIN, lmax = INT_MIN, i;
    for (i = r+1; i<rt; ++i)
    {
        lmax = helper(grid, i, c, rt, ct,rval) + (grid[i][c] - grid[r][c]);
        if (lmax > max)
            max = lmax;
    }
    for (i = c+1; i<ct; ++i)
    {
        lmax = helper(grid, r, i, rt, ct,rval) + (grid[r][i] - grid[r][c]);
        if (lmax > max)
            max = lmax;
    }

    
    return ;
}
public:
    int maxScore(vector<vector<int>>& grid) {
        int rt = grid.size();
        int ct = grid[0].size();
        int rval = INT_MIN;
        return helper(grid, 0,0, rt, ct, rval);
    }
};

int main() {
    Solution s;
    {
        vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
        cout << s.maxScore(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{4,3,2},{3,2,1}};
        cout << s.maxScore(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
        cout << s.maxScore(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,2,3,4,5,6}};
        cout << s.maxScore(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,2},{3,4},{5,6},{7,8}};
        cout << s.maxScore(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,9,9,9,9,9,9,9,9,9},{9,1,9,9,9,9,9,9,9,9},{9,9,1,9,9,9,9,9,9,9},{9,9,9,1,9,9,9,9,9,9},{9,9,9,9,1,9,9,9,9,9},{9,9,9,9,9,1,9,9,9,9},{9,9,9,9,9,9,1,9,9,9},{9,9,9,9,9,9,9,1,9,9},{9,9,9,9,9,9,9,9,1,9},{9,9,9,9,9,9,9,9,9,1}};
        cout << s.maxScore(grid) << endl;
    }

    return 0;
}