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
    int maxOperations(string s) {
        int len = s.length();
        int result = 0;
        int i = 0;
        int onecount = 0;
        for(;i<len;++i) {
            if (s[i] == '1')
                ++onecount;
            else {
                while((i<len) && (s[i] == '0'))
                    ++i;
                if (i < len)
                    --i; // step back for the for loop
                result += onecount;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.maxOperations("1001101") << endl;
    cout << s.maxOperations("1111") << endl;
    cout << s.maxOperations("00111") << endl;
    cout << s.maxOperations("0101") << endl;
    cout << s.maxOperations("111000") << endl;
    return 0;
}