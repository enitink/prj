#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<vector<int> > &mat, int n, int m, int k, int r, int c)
    {
        if (mat[r][c] == 1)
        {
            if(k == 0)
                return INT_MAX;
            --k;
        }
        
        if (mem[r][c])
            return mem[r][c];

        int min = INT_MAX;
        // up
        if ((r-1) >= 0)
        {
            int lmin = helper(mat, n, m, k, r - 1, c);
            if (lmin < min)
            {
                min = lmin;
            }
        }
        
        // down
        if ((r+1) < n)
        {
            int lmin = helper(mat, n, m, k, r + 1, c);
            if (lmin < min)
            {
                min = lmin;
            }
        }
        
        // right
        if ((c+1) < m)
        {
            int lmin = helper(mat, n, m, k, r, c + 1);
            if (lmin < min)
            {
                min = lmin;
            }
        }
        
        // left
        if ((c-1) < m)
        {
            int lmin = helper(mat, n, m, k, r, c - 1);
            if (lmin < min)
            {
                min = lmin;
            }
        }
        
        mem[r][c] = min + 1;

        return mem[r][c];
    }
  public:

    int shotestPath(vector<vector<int> > mat, int n, int m, int k) {
        mem.resize(n);
        for(int i = 0; i < n; ++i)
            mem[i].resize(m);
        mem[n-1][m-1] = -1;
        
        //int helper(vector<vector<int>> &mat, int n, int m, int& k, int r, int c)
        helper(mat, n, m, k, 0, 0);

        return mem[n-1][m-1];
    }

    vector<vector<int> > mem;
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