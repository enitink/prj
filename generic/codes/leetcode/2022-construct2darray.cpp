#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n != original.size())
            return {};
        vector<vector<int>> res(m, vector<int>(n,0));
        int i = 0;
        for(auto& v:original) {
            int r = i/n;
            int c = i%n;
            res[r][c] = v;
            ++i;
        }
        return res;
    }
};

int main() {
    Solution s;
    {
        //original = [1,2,3,4], m = 2, n = 2
        vector<int> original = {1,2,3,4};
        /*vector<vector<int>> res = s.construct2DArray(original, 2, 2);
        for(auto& v:res) {
            for(auto& i:v) {
                cout<<i<<" ";
            }
            cout<<endl;
        }*/
    }
    {
        //original = [1,2,3], m = 1, n = 3
        vector<int> original = {1,2,3};
        vector<vector<int>> res = s.construct2DArray(original, 1, 3);
        for(auto& v:res) {
            for(auto& i:v) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    {
        //original = [1,2], m = 1, n = 1
        vector<int> original = {1,2};
        vector<vector<int>> res = s.construct2DArray(original, 1, 1);
        /*for(auto& v:res) {
            for(auto& i:v) {
                cout<<i<<" ";
            }
            cout<<endl;
        }*/
    }
}