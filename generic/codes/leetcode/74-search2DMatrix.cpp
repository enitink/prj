#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int rowsize;
    int colsize;

    int getValue(vector<vector<int> >& matrix, int position)
    {
        int row = position/colsize;
        int col = position%colsize;

        return matrix[row][col];
    }

    int binarysearch(vector<vector<int> >& matrix, int st, int end, int target)
    {
        if (end < st)
            return -1;
        int pos = -1;
        int mid = (st+end)/2;
        if ( target == getValue(matrix, mid) )
            return mid;
        else if (target < getValue(matrix, mid))
            pos = binarysearch(matrix, st, mid - 1, target);
        else
            pos = binarysearch(matrix, mid + 1, end, target);

        return pos;
    }
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        rowsize = matrix.size();
        colsize = matrix[0].size();
        bool result = (binarysearch(matrix, 0, rowsize * colsize - 1, target) == -1) ?
                        false : true;
        return result;
    }
};

int main()
{
    vector<vector<int> > matrix;
    {
        vector<int> row;
        row.push_back(1); row.push_back(3); row.push_back(5); row.push_back(7);
        matrix.push_back(row);
    }
    {
        vector<int> row;
        row.push_back(10); row.push_back(11); row.push_back(16); row.push_back(20);
        matrix.push_back(row);
    }
    {
        vector<int> row;
        row.push_back(23); row.push_back(30); row.push_back(34); row.push_back(60);
        matrix.push_back(row);
    }
    Solution ob;
    cout << ob.searchMatrix(matrix, 3) << endl;
    cout << ob.searchMatrix(matrix, 13) << endl;
    cout << ob.searchMatrix(matrix, 7) << endl;
    cout << ob.searchMatrix(matrix, 9) << endl;
    cout << ob.searchMatrix(matrix, 21) << endl;
    cout << ob.searchMatrix(matrix, 60) << endl;

    return 0;
}