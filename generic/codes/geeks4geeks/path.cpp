#include <iostream>
#include <vector>

using namespace std;

typedef struct _minK
{
    _minK(): min(INT_MAX), k(0) {}
    
    int min;
    int k;
}minK;

class Solution {
    minK helper(vector<vector<int> > &mat, int n, int m, int& k, int r, int c)
    {
        if (mat[r][c] == 1)
        {
            if((k == 0) || (mem[r][c].k < k))
                return minK();
            ++k;
        }
        
        if (mem[r][c])
            return mem[r][c];

        int min = INT_MAX;
        int mk = k;
        // up
        if ((r-1) >= 0)
        {
            int lmin = helper(mat, n, m, k, r - 1, c);
            if (lmin < min)
            {
                min = lmin;
                mk = k;
            }
        }
        
        // down
        if ((r+1) < n)
        {
            int lmin = helper(mat, n, m, k, r + 1, c);
            if (lmin < min)
            {
                min = lmin;
                mk = k;
            }
        }
        
        // right
        if ((c+1) < m)
        {
            int lmin = helper(mat, n, m, k, r, c + 1);
            if (lmin < min)
            {
                min = lmin;
                mk = k;
            }
        }
        
        // left
        if ((c-1) < m)
        {
            int lmin = helper(mat, n, m, k, r, c - 1);
            if (lmin < min)
            {
                min = lmin;
                mk = k;
            }
        }
        
        mem[r][c].min = min;
        mem[r][c].k = mk;
        
        return mem[r][c];
    }
  public:

    int shotestPath(vector<vector<int> > mat, int n, int m, int k) {
        mem.resize(n);
        mem[n-1][m-1] = -1;
        for(int i = 0; i < n; ++i)
            mem[i].resize(m);
        
        //int helper(vector<vector<int>> &mat, int n, int m, int& k, int r, int c)
        int mk = 0;
        shortestPath(mat, n, m, mk);
        
        return mem[n-1][m-1];
    }
    
    vector<vector<minK> > mem;
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int> > mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}