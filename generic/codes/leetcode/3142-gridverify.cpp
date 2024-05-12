class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int i,j;
        for(i=0; i<r; ++i) {
            for(j=0; j<c; ++j) {
                if (i+1<r)
                    if (grid[i][j]!=grid[i+1][j])
                        return false;
                if (j+1<c)
                    if (grid[i][j+1]==grid[i][j])
                        return false;
            }
        }
        return true;
    }
};