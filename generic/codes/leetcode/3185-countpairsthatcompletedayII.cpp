#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <stack>



using namespace std;

class Solution {

    map<int, long long> values;

    long long factorial(int n) {
        if (values.find(n) != values.end())
            return values[n];
        long long result = 0;
        for (int i = n; i >= 2; --i) {
            if (values.find(i) != values.end()) {
                result += values[i];
                break;
            } else {
                result += (i - 1);
            }
        }
        values[n] = result;
        return result;
    }
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        //values[1] = 0;
        //values[2] = 1;

        map<int, int> mymap;
        long long result = 0;
        int i, j, len = hours.size();
        for(auto& h : hours){
            mymap[h%24]++;
        }
        map<int, bool> visited;
        for(auto& m : mymap) {
            //cout << endl << m.first << " : " << m.second;
            if((m.second > 1) && (((m.first * 2) % 24) == 0)) {
                result += factorial(m.second);
                visited[m.first] = true;
            } else {
                if(mymap.find(24-m.first) != mymap.end()) {
                    if ((24-m.first != m.first ) && (visited[m.first] == false)){
                        result += (m.second * mymap[24 - m.first]);
                        visited[m.first] = true;
                        visited[24 - m.first] = true;
                    }
                }
            }
            //cout << " : " << result;
        }
        //cout << endl;
        return result;
    }
};

int main() {
    Solution s;
    vector<int> hours = {11,13};
    cout << endl << s.countCompleteDayPairs(hours) << endl;
    return 0;
}