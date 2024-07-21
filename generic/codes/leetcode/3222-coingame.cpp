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
    string losingPlayer(int x, int y) {
        int count = 0;
        while((x*75)+(y*10) >= 115) {
            ++count;
            if (x < 1)
                break;
            if (y < 4)
                break;
            x--;
            y-=4;
        }
        return (count%2)?"Alice":"Bob";
    }
};