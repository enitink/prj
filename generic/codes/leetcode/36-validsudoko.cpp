#include <iostream>
#include <vector>

using namespace std;

// It's a map problem, just we need to find out how to track. 9 map for row, 9 map for column and 9 for 3x3 ones
// Row and column is easy.. as row and column can be used as the which one we are tracking, but for 3x3 , the map to look into
// can be cacluated by i/3 and j/3 .. grouping 3 by 3. And the thing to keep in mind, this problem only is looking for looking
// into what's present in the input, possibly the sudoko given might not be solvable.

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int rowMap[9][9] = {};
        int colMap[9][9] = {};
        int txtmap[9][9] = {};

        int i, j;
        for(i=0; i<9; ++i)
        {
            for(j=0;j<9;++j)
            {
                if (board[i][j] == '.')
                    continue;
                int val = (board[i][j] - '0') - 1;
                int txtmapVal = ((i/3) * 3) + (j/3);
                if ((rowMap[i][val]) || (colMap[j][val]) || txtmap[txtmapVal][val])
                    return false;
                rowMap[i][val] = colMap[j][val] = txtmap[txtmapVal][val] = 1;
            }
        }
        return true;
    }
private:
};

int main()
{
    {
        vector<vector<char> > board;
        board.resize(9);
        int i = 0, j;
        for( ; i<9; ++i)
        {
            board[i].resize(9);
            for(j=0;j<9;++j)
            {
                cin >> board[i][j];
            }
        }
        Solution ob;
        cout << ob.isValidSudoku(board) << endl;
    }
    {
        vector<vector<char> > board;
        board.resize(9);
        int i = 0, j;
        for( ; i<9; ++i)
        {
            board[i].resize(9);
            for(j=0;j<9;++j)
            {
                cin >> board[i][j];
            }
        }
        Solution ob;
        cout << ob.isValidSudoku(board) << endl;
    }
    return 0;

}