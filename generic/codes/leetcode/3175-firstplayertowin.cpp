#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int i = 0;
        int pos = skills[0] > skills[1] ? 0 : 1;
        int len = skills.size();
        int lwin = 1;
        for (i=2;i<len;++i) {
            if (lwin == k)
                break;
            if (skills[i] < skills[pos]) {
                ++lwin;
            } else {
                lwin = 1;
                pos = i;
            }
        }
        return pos;
    }
};

int main(){
    Solution solution;
    {
        vector<int> skills = {4,2,6,3,9};
        int k = 2;
        cout << endl << solution.findWinningPlayer(skills, k) << endl;
    }
    {
        vector<int> skills = {2,5,4};
        int k = 3;
        cout << solution.findWinningPlayer(skills, k) << endl;
    }
    {
        vector<int> skills = {1, 2, 3, 4, 5};
        int k = 1;
        cout << solution.findWinningPlayer(skills, k) << endl;
    }
    {
        vector<int> skills = {4,2,6,3,9};
        int k = 3;
        cout << solution.findWinningPlayer(skills, k) << endl;
    }
    return 0;
}