#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    void helper(int n, vector<string>& result, string s) {
        if(n == 1) {
            result.push_back(s);
            return;
        }
        int len = s.length();
        if(s[len - 1] == '1') {
            helper(n-1, result, s + '1');
            helper(n-1, result, s + '0');
        } else {
            helper(n-1, result, s + '1');
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        helper(n, result, "1");
        helper(n, result, "0");
        return result;
    }
};

int main() {
    Solution s;
    {
        vector<string> result = s.validStrings(3);
        for(auto str : result) {
            cout << str << endl;
        }
    }
    {
        vector<string> result = s.validStrings(1);
        for(auto str : result) {
            cout << str << endl;
        }
    }
    return 0;
}