//
//  sept28q3.cpp
//  leetCode
//
//  Created by Nitin Kumar on 28/09/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>
#include <limits>
#include <iterator>

using namespace std;

class Solution {
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> pq;
    map<string, vector<int>> mp;

    bool almostEq(string& word1, string& word2) {
        int dc = 0;
        for(int i=0; i<word1.size(); ++i){
            if (word1[i] != word2[i]) {
                //word1[i] = word2[i];
                ++dc;
            }
            if (dc > 1)
                return false;
        }
        //cout << word1 << " : "<< word2 << endl;
        return true;
    }

    void helper(string& word1, string& word2, string w1, int pos, vector<int>& mv) {
        if (w1.size() == word2.size()) {
            if (almostEq(w1, word2)) {
                mp[w1] = mv;
                pq.push(w1);
            }
            return;
        }
        int i;
        for(i = pos; i<word1.size(); ++i) {
            helper(word1, word2, w1, i+1, mv);
            mv.push_back(i);
            helper(word1, word2, w1 + word1[i], i+1, mv);
            mv.pop_back();
        }
    }

public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> mv;
        helper(word1, word2, "", 0, mv);
        if (pq.size()) {
            //cout << "\t\t" << pq.top() << " : " ;
            return mp[pq.top()];
        }
        else
            return vector<int>();
    }
};

int main() {
    {
        Solution ob;
        vector<int> result = ob.validSequence("vbcca", "abc");
        cout << "[";
        for(auto& r:result) {
            cout << r << ",";
        }
        cout << "]" << endl;
    }
    {
        Solution ob;
        vector<int> result = ob.validSequence("bacdc", "abc");
        cout << "[";
        for(auto& r:result) {
            cout << r << ",";
        }
        cout << "]" << endl;
    }
    {
        Solution ob;
        vector<int> result = ob.validSequence("aaaaaa", "aaabc");
        cout << "[";
        for(auto& r:result) {
            cout << r << ",";
        }
        cout << "]" << endl;
    }
    {
        Solution ob;
        vector<int> result = ob.validSequence("abc", "ab");
        cout << "[";
        for(auto& r:result) {
            cout << r << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
