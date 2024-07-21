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
#include <memory>
#include <array>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        int ans = len;
        int i;
        vector<vector<int>> mq(3, vector<int>(26,-1));
        for (i=0; i<len; i++) {
            if (mq[0][s[i]-'a'] == -1) {
                mq[0][s[i]-'a'] = i;
            } else if (mq[1][s[i]-'a'] == -1) {
                mq[1][s[i]-'a'] = i;
            } else if (mq[2][s[i]-'a'] == -1) {
                mq[0][s[i]-'a'] = mq[1][s[i]-'a'];
                mq[1][s[i]-'a'] = -1;
                mq[2][s[i]-'a'] = -1;
                ans -= 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.minimumLength("waoji") << endl;
    cout << sol.minimumLength("aabccabba") << endl;
    cout << sol.minimumLength("a") << endl;
    cout << sol.minimumLength("aa") << endl;
    cout << sol.minimumLength("aaa") << endl;
    cout << sol.minimumLength("aaaa") << endl;
    return 0;
}