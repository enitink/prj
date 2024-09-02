#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>
#include <limits>
#include <iterator>


using namespace std;

class Solution {
    

public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        vector<vector<int>> cb(8, vector<int>(8,0));
        int i,j;
        for(i=0;i<8;++i){
            for(j=0;j<8;++j){
                if((i+j)%2==0){
                    cb[i][j]=1;
                }
            }
        }
        int x1 = coordinate1[0]-'a';
        int y1 = coordinate1[1]-'1';
        int x2 = coordinate2[0]-'a';
        int y2 = coordinate2[1]-'1';

        return cb[x1][y1] == cb[x2][y2];
    }
};

int main(){
    Solution sol;
    {
        string coordinate1 = "a1";
        string coordinate2 = "c3";
        cout<<sol.checkTwoChessboards(coordinate1, coordinate2)<<endl;
    }
    {
        string coordinate1 = "a1";
        string coordinate2 = "h3";
        cout<<sol.checkTwoChessboards(coordinate1, coordinate2)<<endl;
    }
    return 0;
}