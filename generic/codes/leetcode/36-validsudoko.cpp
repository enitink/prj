#include <iostream>
#include <vector>

using namespace std;

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