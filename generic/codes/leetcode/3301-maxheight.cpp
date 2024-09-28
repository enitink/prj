//
//  sept28q1.cpp
//  leetCode
//
//  Created by Nitin Kumar on 28/09/24.
//

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

//Constraints:
//1 <= maximumHeight.length <= 105
//1 <= maximumHeight[i] <= 109

// 2,3,3,4
// 1,2,2

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        int i = 0, s=(int)maximumHeight.size();
        long long result = 0;
        for(; i<s; ++i) {
            if (maximumHeight[i] <= 0)
                return -1;
            if ((i<s-1)&&(maximumHeight[i] <= maximumHeight[i+1])){
                maximumHeight[i+1] = maximumHeight[i] - 1;
            }
            result += maximumHeight[i];
        }
        return result;
    }
};

/*
int main() {
    Solution ob;
    {
        vector<int> maximumHeight = {2,3,4,3};
        cout << ob.maximumTotalSum(maximumHeight) << endl;
    }
    {
        vector<int> maximumHeight = {15,10};
        cout << ob.maximumTotalSum(maximumHeight) << endl;
    }
    {
        vector<int> maximumHeight = {2,2,1};
        cout << ob.maximumTotalSum(maximumHeight) << endl;
    }
    {
        vector<int> maximumHeight = {6,6,6,3,7,2,6,5};
        cout << ob.maximumTotalSum(maximumHeight) << endl;
    }
    
    return 0;
}
*/
