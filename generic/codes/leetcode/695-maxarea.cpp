class Solution {
private:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValidCell(vector<vector<int>>& grid, int r, int c){
        return (r>=0 && c>=0 && r<grid.size() && c<grid[0].size()) ? true : false;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0, r, c;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        pair<int, int> curr;
        
        for(r=0;r<rows;++r){
            for(c=0;c<cols;++c) {
                int lresult = 0;
                if ((!visited[r][c]) && (grid[r][c])) {
                    q.push({r,c});
                    visited[r][c] = true;
                    ++lresult;
                    while(!q.empty()) {
                        curr = q.front();
                        q.pop();
                        
                        for (auto& d : dir) {
                            int di = curr.first + d[0];
                            int dj = curr.second + d[1];
                            
                            if (isValidCell(grid, di, dj)
                               && (!visited[di][dj])
                               && (grid[di][dj])) {
                                ++lresult;
                                visited[di][dj] = true;
                                q.push({di,dj});
                            } 
                        }
                    }
                }
                if (lresult > result)
                    result = lresult;
            }
        }
        
        return result;
    }
};