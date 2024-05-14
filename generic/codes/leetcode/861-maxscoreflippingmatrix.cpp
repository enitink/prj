class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int i=0,j=0;
        int result = (1<<(c-1)) * r;
        for(i=1;i<c;++i) {
            int count0s = 0;
            for(j=0;j<r;++j) {
                if (grid[j][0] != grid[j][i]) {
                    ++count0s;
                }
            }
            count0s = count0s > (r - count0s) ?  count0s : r - count0s;
            int lresult = ((1<<(c-i-1)) * count0s);
            result += lresult;
        }
        return result;
    }
};