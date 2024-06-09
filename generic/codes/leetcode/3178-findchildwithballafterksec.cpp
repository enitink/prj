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
    int numberOfChild(int n, int k) {
        n--; //as in a given time only n-1 will be traversed. Never all n in each round
        int rounds = k / n; // this to find out if moving front or back.
        int rem = k % n;
        if (rounds%2)     // means this is moving back
            return n - rem;
        else             // means moving front
            return rem;

    }
};


int main(){
    Solution solution;
    {
        cout << endl << solution.numberOfChild(3,5);
        cout << endl << solution.numberOfChild(5,9);
        cout << endl << solution.numberOfChild(4,2);
    }
    return 0;
}