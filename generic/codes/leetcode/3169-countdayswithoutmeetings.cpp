#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>


using namespace std;

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

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}


class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> result;
        vector<int> newInterval = intervals[0];
        int len = intervals.size(), i = 1;

        for ( ;i<len; ++i)
        {
            if (newInterval[1] < intervals[i][0]) {
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
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.size() == 0)
            return 0;
        vector<vector<int>> merged = merge(meetings);
        printvector(merged);
        int result = merged[0][0] - 1;
        int i = 1, len = merged.size();
        if (merged.size() == 1) {
            return (merged[0][0] - 1) +  (days - merged[0][1]);
        }
        for (;i<len;++i) {
            result += (merged[i][0] - merged[i-1][1] - 1);
        }
        cout << result << endl;

        result += (days - merged[i-1][1]);
        return result;
    }
};

int main()
{
    Solution sol;
    {
        // 8  [[3,4],[4,8],[2,5],[3,8]]
        vector<vector<int>> intervals = {{2,3},{3,5}, {8,8}};
        cout << endl << sol.countDays(8, intervals);
    }

    return 0;
}
