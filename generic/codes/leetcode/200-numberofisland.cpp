class Solution {
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isValidCell(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> traversalQueue;
        int r, c, result = 0;
        
        for(r=0; r<rows; ++r) {
            for(c=0; c<cols; ++c) {
                if ((!visited[r][c]) && (grid[r][c] == '1')) {
                    ++result;
                    queue<pair<int, int>> traversalQueue;
                    traversalQueue.push({r, c});
                    visited[r][c] = true;
                    
                    while(!traversalQueue.empty()) {
                        auto curr = traversalQueue.front();
                        traversalQueue.pop();
                        
                        for (auto& d : dir) {
                            int di = curr.first + d[0];
                            int dj = curr.second + d[1];
                            
                            if (isValidCell(grid, di, dj) 
                                && (!visited[di][dj])
                                && (grid[di][dj] == '1')) {
                                visited[di][dj] = true;
                                traversalQueue.push({di, dj});
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};