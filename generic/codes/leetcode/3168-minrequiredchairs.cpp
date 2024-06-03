#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>


using namespace std;

class Solution {
public:
    int minChairs(string s) {
        int result = 0;
        int curr = 0;
        for (auto c : s) {
            if (c == 'E') {
                curr++;
            } else {
                curr--;
            }
            if (curr > result)
                result = curr;
        }
        return result;
    }
};