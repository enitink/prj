class Solution {
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool isValidCell(vector<vector<int>>& grid, int r, int c) {
        return (r>=0 && c>=0 && r<grid.size() && c<grid[0].size()) ? true : false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int r, c, result = 0;
        
        queue<pair<int, int>> qu;
        queue<pair<int, int>> squ;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (r=0; r<rows; ++r) {
            for (c=0; c<cols; ++c) {
                if (grid[r][c] == 2) {
                    squ.push({r,c});
                    visited[r][c] = true;
                }
            }
        }

        do {
            swap( squ, qu );
            while(!qu.empty()) {
                pair<int, int> curr = qu.front();
                qu.pop();
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];

                    if (isValidCell(grid, di, dj) 
                       && (grid[di][dj] == 1)
                       && (!visited[di][dj])) {
                        squ.push({di,dj});
                        visited[di][dj] = true;
                    }
                }
            }
            if (squ.empty())
                break;
            ++result;
        } while(true);
        
        for (r=0; r<rows; ++r) {
            for (c=0; c<cols; ++c) {
                if ((grid[r][c] == 1) && (!visited[r][c]))
                    return -1;
            }
        }
        
        return result;
    }
};