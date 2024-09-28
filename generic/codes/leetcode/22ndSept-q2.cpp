#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>

using namespace std;

// mountain height / size of workertimes
// 4/3 
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(workerTimes.begin(), workerTimes.end());
        long long seconds = 0;
        int i = 1, s=workerTimes.size();
        for(;i<=s;++i) {
            int j = mountainHeight / s;
            if(mountainHeight % s <= i) {
                j++;
            }
            second += (( (j * (j+1)) / 2) * workerTimes[i-1]);
        }
        return seconds;
    }
};

int main() {
    Solution ob;
    {
        //Input: mountainHeight = 10, workerTimes = [3,2,2,4]
        vector<int> workerTimes = {3,2,2,4};
        cout << ob.minNumberOfSeconds(10, workerTimes) << endl;
    }
    {
        // Input: mountainHeight = 4, workerTimes = [2,1,1]
        vector<int> workerTimes = {2,1,1};
        cout << ob.minNumberOfSeconds(4, workerTimes) << endl;
    }
    {
        // Input: mountainHeight = 5, workerTimes = [1]
        vector<int> workerTimes = {1};
        cout << ob.minNumberOfSeconds(5, workerTimes) << endl;
    }
}