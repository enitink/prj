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
    int minChanges(int n, int k) {
        int i = 0;
        int result = 0;
        if (n==k)
            return result;

        for(;i<32;++i) {
            int ni = n & 1;
            int ki = k & 1;
            //cout << endl << ni << " : " << ki;
            if((ni != ki) && (!ni)){
                return -1;
            }
            if(ni != ki)
                ++result;
            n >>= 1;
            k >>= 1;
            if (!n && !k)
                break;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.minChanges(2, 47) << endl;
    return 0;
}