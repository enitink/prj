#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <stack>



using namespace std;


class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> m;
        for(auto& p: power) {
            m[p] += p;
        }
        long long result = 0;
        auto it = m.rbegin();
        for(;it != m.rend();++it) {
            long long lresult = 0;
            for(auto& p: m) {
                if(p.first < it->first) {
                    lresult += p.second;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        vector<int> power = {1, 1, 3, 4};
        cout << s.maximumTotalDamage(power) << endl;
    }
    {
        vector<int> power = {7,1,6,6};
        cout << s.maximumTotalDamage(power) << endl;
    }
    return 0;
}