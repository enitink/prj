#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int i = 0;
        int len = s.length();
        string result;
        result.resize(len);

        for(;i<len;++i) {
            result[i] = (s[i] - 'a' + k) % 26;
        }
        return result;
    }
};

int main() {
    Solution s;
    string str = "xyz";
    cout << s.getEncryptedString(str, 2) << endl;
    return 0;
}