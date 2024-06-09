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

void printVector(vector<int>& r){
    for(auto e:r)
        cout << e << " ";
    cout << endl;

}

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int result = 0, lresult = 0 ;
        int rcount = rewardValues.size();

        for(int i = 0; i < rcount; ++i)
        {
            int tempi = i;
            int pos = 0;
            while(tempi)
            {
                if (tempi&1)
                {
                    lresult += rewardValues[pos];
                }
                tempi >>= 1;
                ++pos;
            }
            if (lresult > result)
                result = lresult;
        }

        return result;
    }
};


int main(){
    Solution solution;
    {
        vector<int> rewardValues = {1,6,4,3,2};
        cout << solution.maxTotalReward(rewardValues) << endl;
    }
    
    return 0;
}