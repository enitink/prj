/**************************************************************************************************
566. Reshape the Matrix

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.ß

Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2:


Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void mapper(int mr, int mc, int r, int c, int& mapr, int& mapc)
    { 
    }
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
        int mr = mat.size();
        int mc = 0;
        if (mr)
            mc = mat[0].size();
        else
            return mat;

        if ((r*c) != (mr*mc))
            return mat;
        
        return mat;
    }
};

int main()
{
    Solution ob;

    {
        vector<vector<int> > mat;
        mat.resize(2);
        mat[0].resize(2);
        mat[1].resize(2);
        mat[0][0] = 1; mat[0][1] = 2;
        mat[1][0] = 3; mat[1][1] = 4;
        vector<vector<int> > result = ob.matrixReshape(mat, 1, 4);
    }
}