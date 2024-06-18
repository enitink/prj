#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <stack>



using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int result = 0, i, j, len = hours.size();
        for(i=0;i<len - 1;++i) {
            for(j=i+1;j<len;++j) {
                if (((hours[i] + hours[j]) % 24)  == 0)
                    ++result;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}