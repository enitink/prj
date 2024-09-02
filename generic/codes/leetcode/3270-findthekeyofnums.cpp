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
    int generateKey(int num1, int num2, int num3) {
        int d = 10;
        int mul = 1;
        int result = 0;
        for(int i = 0; i<4; ++i) {
            int m = (num1%d);
            if (num2%d < m)
                m = num2%d;
            if (num3%d < m)
                m = num3%d;
            //cout << m << ":";
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            result = m * mul + result;
            mul *= 10;
        }
        //cout << endl ;
        return result;
    }
};

int main() {
    Solution s;
    cout << s.generateKey(1234, 5678, 9012) << endl;
    cout << s.generateKey(1,10,1000) << endl;
    return 0;
}