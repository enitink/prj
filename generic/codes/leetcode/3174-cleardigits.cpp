#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string res = s;
        int i = 0, j = 0;
        for(; i<s.size(); ++i, ++j){
            if(s[i] >= '0' && s[i] <= '9'){
                j-=2;
                continue;
            }
            res[j] = s[i];
        }
        cout << j;
        return res.substr(0, j);
    }
};


int main(){
    Solution solution;
    {
        string s = "abc";
        cout << solution.clearDigits(s) << endl;
    }
    {
        string s = "cb34";
        cout << solution.clearDigits(s) << endl;
    }
    {
        string s = "a1b2c3d4e";
        cout << solution.clearDigits(s) << endl;
    }
    
    return 0;
}