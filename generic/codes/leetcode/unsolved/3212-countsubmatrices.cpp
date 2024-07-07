#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct _xy {
    int x;
    int y;
    _xy(): x(0), y(0) {}
} xy;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<xy>> tracker(m, vector<xy>(n));
        int result = 0,i,j;
    
        tracker[0][0].x = grid[0][0] == 'X';
        tracker[0][0].y = grid[0][0] == 'Y';
    
        for(i=1;i<m;i++) {
            if (grid[i][0] == 'X') {
                tracker[i][0].x = tracker[i-1][0].x + 1;
                tracker[i][0].y = tracker[i-1][0].y;
            } else if (grid[i][0] == 'Y') {
                tracker[i][0].x = tracker[i-1][0].x;
                tracker[i][0].y = tracker[i-1][0].y + 1;
            } else {
                tracker[i][0].x = tracker[i-1][0].x;
                tracker[i][0].y = tracker[i-1][0].y;
            }
            if ((tracker[i][0].x) && (tracker[i][0].x == tracker[i][0].y))
                result++;
        }

        for(i=1;i<n;i++) {
            if (grid[0][i] == 'X') {
                tracker[0][i].x = tracker[0][i-1].x + 1;
                tracker[0][i].y = tracker[0][i-1].y;
            } else if (grid[0][i] == 'Y') {
                tracker[0][i].x = tracker[0][i-1].x;
                tracker[0][i].y = tracker[0][i-1].y + 1;
            } else {
                tracker[0][i].x = tracker[0][i-1].x;
                tracker[0][i].y = tracker[0][i-1].y;
            }
            if ((tracker[0][i].x) && (tracker[0][i].x == tracker[0][i].y))
                result++;
        }

        for(i=1;i<m;i++) {
            for(j=1; j<n; j++) {
                tracker[i][j].x = tracker[i][j-1].x + tracker[i-1][j].x;
                tracker[i][j].y = tracker[i][j-1].y + tracker[i-1][j].y;

                if(grid[i][j] == 'X') {
                    tracker[i][j].x += 1;
                }
                else if (grid[i][j] == 'Y') {
                    tracker[i][j].y += 1;
                }
                if ((tracker[i][j].x) && (tracker[i][j].x == tracker[i][j].y))
                    result++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        vector<vector<char>> grid = {
            {'X', 'Y', '.'},
            {'Y', '.', '.'}
        };
        cout << s.numberOfSubmatrices(grid) << endl;
    }
    return 0;
}