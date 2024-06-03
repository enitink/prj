#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}


void printvector(vector<vector<int>>& intervals) {
    cout << "[";
    for (auto i : intervals) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> result;
        vector<int> newInterval = intervals[0];
        int len = intervals.size(), i = 1;

        for ( ;i<len; ++i)
        {
            if (newInterval[1] <= intervals[i][0]) {
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
            else
            {
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                newInterval[0] = min(newInterval[0], intervals[i][0]);
            }
        }
        result.push_back(newInterval);

        return result;
    }
};

int main()
{
    Solution sol;
    {
        vector<vector<int>> intervals = {{3,4},{4,8},{2,5},{3,8}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{4,5}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{2,3}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{0,4}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res); 
    }
    {
        vector<vector<int>> intervals = {{1,4},{0,0}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{0,1}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,4},{0,0},{3,5},{6,8}};
        vector<vector<int>> res = sol.merge(intervals);
        printvector(res);        
    }
    return 0;
}