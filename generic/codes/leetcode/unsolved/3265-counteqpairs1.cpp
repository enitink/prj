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
    
    bool almostEq(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        char freq[10] = {};
        for (int i = 0; i < strA.size(); i++) {
            freq[strA[i] - '0']++;
        }
        
        for (int i = 0; i < strB.size(); i++) {
            freq[strB[i] - '0']--;
        }
        
        int diffCount = 0;
        for (int i = 0; i < 10; i++) {
            if (freq[i] != 0) {
                diffCount++;
            }
        }

        return diffCount <= 1;
    }

public:
    int countPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] || almostEq(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    {
        vector<int> nums = {3,12,30,17,21};
        cout << s.countPairs(nums) << endl;
    }
    {
        vector<int> nums = {1,1,1,1,1};
        cout << s.countPairs(nums) << endl;
    }
    {
        vector<int> nums = {123,231};
        cout << s.countPairs(nums) << endl;
    }
    return 0;
}