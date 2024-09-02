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
    bool isValid(string& s, int st, int end, int k) {
        int zc=0, oc=0, i=st;
        for(; i<=end; ++i) {
            if(s[i] == '0')
                zc++;
            else
                oc++;
            if(zc>k && oc>k)
                return false;
        }
        return true;
    }
public:
    int countKConstraintSubstrings(string s, int k) {
        int st=0, zc=0, oc=0, i=0, len=s.length(), j;
        int result = 0;
        for(;i<len;++i){
            for(j=i;j<len;++j){
                result += (isValid(s,i,j,k)?1:0);
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    cout << s.countKConstraintSubstrings("10101", 1) << endl;
    cout << s.countKConstraintSubstrings("1010101", 2) << endl;
    cout << s.countKConstraintSubstrings("11111", 1) << endl;
    return 0;
}