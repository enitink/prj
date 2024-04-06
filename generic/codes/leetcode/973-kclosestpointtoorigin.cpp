#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class positionData {
public:
    positionData(vector<int> p, int d): position(p), distance(d) {}
    vector<int> position;
    int distance;
};

class Compare {
public:
    bool operator()(positionData a, positionData b)
    {
        return a.distance > b.distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<positionData, vector<positionData>, Compare> pq;
        for (auto& p : points)
        {
            int distance = p[0] * p[0] + p[1] * p[1];
            pq.push(positionData(p, distance));
        }
        vector<vector<int>> result;
        while(k--)
        {
            result.push_back(pq.top().position);
            pq.pop();
        }
        return result;
    }
};

void printVector(vector<vector<int>>& points)
{
    cout << "[";
    for (auto& r : points)
    {
        cout << "[";
        for (auto& c : r)
        {
            cout << c << " ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sln;
    {
        vector<vector<int>> points = {{1,3},{-2,2}};
        int k = 1;
        vector<vector<int>> result = sln.kClosest(points, k);
        printVector(result);
    }
    {
        vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
        int k = 2;
        vector<vector<int>> result = sln.kClosest(points, k);
        printVector(result);
    }
    {
        vector<vector<int>> points = {{1,3},{-2,2},{2,-2}};
        int k = 2;
        vector<vector<int>> result = sln.kClosest(points, k);
        printVector(result);
    }

    return 0;
}