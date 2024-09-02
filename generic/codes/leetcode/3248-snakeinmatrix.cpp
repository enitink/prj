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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        for(auto& c:commands) {
            if(c=="UP") {
                row--;
            } else if(c=="DOWN") {
                row++;
            } else if (c=="RIGHT") {
                col++;
            } else if (c=="LEFT") {
                col--;
            }
        }
        return (row * n) + col;
    }
};

int main() {

}