#include <iostream>
#include <vector>

using namespace std;

class Solution {

int helper(vector<vector<int>>& grid, int r, int c, int rt, int ct) {
    if ((r < 0) || (c < 0) || (r >= rt) || (c >= ct))
        return 0;
    if (grid[r][c] == 0)
        return 0;

    int rcval = grid[r][c];
    grid[r][c] = 0;
    int max = helper(grid, r+1,c,rt,ct); //down
    int lmax = helper(grid, r-1,c,rt,ct); //up
    if (max < lmax)
        max = lmax;
    lmax = helper(grid, r,c+1,rt,ct); // right
    if (max < lmax)
        max = lmax;
    lmax = helper(grid, r, c-1,rt,ct); // left
    if (max < lmax)
        max = lmax;
    grid[r][c] = rcval;
    return grid[r][c] + max;
}
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int i,j, max = 0;
        for(i=0;i<r;++i){
            for(j=0;j<c;++j){
                int lmax = helper(grid, i,j, r, c);
                if (lmax > max)
                    max = lmax;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
        cout << s.getMaximumGold(grid) << endl;
    }
   {
        vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
        cout << s.getMaximumGold(grid) << endl;
    }
    return 0;
}