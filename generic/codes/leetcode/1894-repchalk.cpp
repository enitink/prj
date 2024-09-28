#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for(auto& c:chalk) {
            k -= c;
            sum += c;
            if(k < 0) {
                return &c - &chalk[0];
            }
        }
        k %= sum;
        return chalkReplacer(chalk, k);
    }
};

int main() {
    Solution solution;
    {
        vector<int> chalk = {5,1,5};
        int k = 22;
        cout << solution.chalkReplacer(chalk, k) << endl;
    }
    {
        vector<int> chalk = {3,4,1,2};
        int k = 27;
        cout << solution.chalkReplacer(chalk, k) << endl;
    }
    return 0;
}