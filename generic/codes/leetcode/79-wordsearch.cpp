#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool helper(vector<vector<char>>& board, string& word, int r, int c, int pos, bool * visited) {
        if (pos == word.size())
            return true;
        int rows = board.size();
        int cols = board[0].size();
        int bpos = r * cols + c;
        if (visited[bpos])
            return false;

        if (board[r][c] != word[pos])
            return false;
        
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;

        int result = false;
        bool visitedAny = false;
        visited[bpos] = true;
        if (r + 1 < rows) { 
            result = helper(board, word, r+1, c, pos+1, visited);
            visitedAny = true;
        }
        if ((!result)  && (r - 1 >= 0)) {
            result = helper(board, word, r-1, c, pos+1, visited);
            visitedAny = true;
        }
        if ((!result) && (c + 1 < cols)) {
            result = helper(board, word, r, c+1, pos+1, visited);
            visitedAny = true;
        }
        if ((!result) && (c - 1 >= 0)) {
            result = helper(board, word, r, c-1, pos+1, visited);
            visitedAny = true;
        }
        visited[bpos] = false;

        return visitedAny ? result : true;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        bool visited[rows * cols];
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                memset(visited, 0, sizeof(visited));
                if (helper(board, word, r, c, 0, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    {
        vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
        };
        cout << s.exist(board, "ABCCED") << endl;
        cout << s.exist(board, "SEE") << endl;
        cout << s.exist(board, "ABCB") << endl;
        cout << s.exist(board, "ABCESEEDASFC") << endl;
        cout << s.exist(board, "Z") << endl;
        cout << s.exist(board, "ASADFB") << endl;
        cout << s.exist(board, "CCEBFD") << endl;
    }
    {
        vector<vector<char>> board = {{'A'}};
        cout << s.exist(board, "A") << endl;
    }
    return 0;
}