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
    bool doesAliceWin(string s) {
        int v = 0;
        for(auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++v;
            }
        }
        if (v%2)
            return true;
        int pv = v;
        v = 0;
        for(auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++v;
                if (pv == v)
                    return true;
            }
            else {
                if (v%2)
                    return true;
            }
        }
        return false;
    }
};

int main