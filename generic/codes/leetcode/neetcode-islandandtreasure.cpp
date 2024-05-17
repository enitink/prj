#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(),i,j;
        int m = grid[0].size();

        queue<pair<int, int>> multiSourceQueue;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    multiSourceQueue.push({i, j});
                } else if (grid[i][j] == -1) {
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = -2;
                }
            }
        }

        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -2) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

            }
        }
    }

private:
    // Directions for moving to neighboring cells: right, left, down, up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Check if a given cell lies within the grid
    
    bool isValidCell(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    /*{
        vector<vector<int>> grid = {{2147483647,-1,0,2147483647},
                                    {2147483647,2147483647,2147483647,-1},
                                    {2147483647,-1,2147483647,-1},
                                    {0,-1,2147483647,2147483647}};
        sol.islandsAndTreasure(grid);
        printMatrix(grid);
    }*/
    {
        vector<vector<int>> grid = {{-1,0,2147483647},
                                    {2147483647,2147483647,-1}};
        sol.islandsAndTreasure(grid);
        printMatrix(grid);
    
    }
    return 0;
}

/*
 [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
*/