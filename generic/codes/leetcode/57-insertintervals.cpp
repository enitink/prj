#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        vector<vector<int>>::iterator it = intervals.begin();
        vector<vector<int>>::iterator end = intervals.end();

        for( ; it!= end; ++it) {
            if (newInterval[1] < (*it)[0] ) {
                result.push_back(newInterval);
                for (; it!= end; ++it) {
                    result.push_back(*it);
                }
                return result;
            } 
            else if (newInterval[0] > (*it)[1]) {
                result.push_back(*it);
            }
            else {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
            }
        }
        if (it == end) {
            result.push_back(newInterval);
        }
        return result;
    }
};

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

int main()
{
    Solution sol;
    {
        vector<vector<int>> intervals = {{1,3},{6,9}};
        vector<int> newInterval = {2,5};
        vector<vector<int>> res = sol.insert(intervals, newInterval);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        vector<int> newInterval = {4,8};
        vector<vector<int>> res = sol.insert(intervals, newInterval);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {};
        vector<int> newInterval = {5,7};
        vector<vector<int>> res = sol.insert(intervals, newInterval);
        printvector(res);
    }
    {
        vector<vector<int>> intervals = {{1,5}};
        vector<int> newInterval = {2,3};
        vector<vector<int>> res = sol.insert(intervals, newInterval);
        printvector(res);
    }
    return 0;
}