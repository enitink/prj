#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


typedef struct _newnum {
    int n;
    int o;
    _newnum(int num, int old): n(num), o(old) {}
}newnum;

class Compare {
public:
    bool operator()(newnum& a, newnum& b) {
        return a.n > b.n;
    }
};

/*
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<newnum, vector<newnum>, Compare> pq;
        for(auto num:nums) {
            int nnum = 0;
            int tnum = num;
            int mul = 1;
            if (num == 0) {
                nnum = mapping[0];
            } else {
                while(num) {
                    nnum += (mapping[num%10] * mul);
                    mul *= 10;
                    num /= 10;
                }
            }
            pq.push({nnum, tnum});
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().o);
            pq.pop();
        }
        return result;
    }
};*/


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0;
            int temp = nums[i];
            // Start making changes from the units place.
            int place = 1;
            // If the value initially is 0, return mapping[0] and index.
            if (temp == 0) {
                storePairs.push_back({mapping[0], i});
                continue;
            }
            // Repeat the process for units, tenths, hundredths.. places.
            while (temp != 0) {
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};

int main() {
    Solution sol;
    {
        vector<int> mapping = {7,9,6,0,4,8,1,5,3,2};
        vector<int> nums;
        int d;
        for(int i=0;i<20000;++i) {
            cin >> d;
            nums.push_back(d);
        }
        vector<int> result = sol.sortJumbled(mapping, nums);
        for(auto num:result) {
            cout << num << endl;
        }
        cout << endl;
    }
    return 0;
}