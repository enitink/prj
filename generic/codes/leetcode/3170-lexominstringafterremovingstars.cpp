#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>


using namespace std;

class PositionData {
public:
    PositionData(char d, int f): data(d), position(f) {}
    PositionData(): data(0), position(0) {}
    char data;
    int position;
};

class Compare {
public:
    bool operator()(PositionData below, PositionData above) {
        if (below.data > above.data) {
            return true;
        }
        else if (below.data < above.data) {
            return false;
        }
        else {
            return below.position < above.position ;
        }
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<PositionData, vector<PositionData>, Compare> pq;
        int i = 0, len = s.length();
        bool starPresent = false;
        for (;i<len;++i) {
            if (s[i] != '*') {
                PositionData ob(s[i], i);
                pq.push(ob);
            } else {
                PositionData d = pq.top();
                pq.pop();
                s[d.position] = '*';
                starPresent = true;
            }
        }
        if (!starPresent)
            return s;
        string result;

        for (i = 0; i < len; ++i) {
            if (s[i] != '*') {
                result += s[i];
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    string data;
    cin >> data;
    string result = s.clearStars(data);
    cout << result << endl;
    return 0;
}