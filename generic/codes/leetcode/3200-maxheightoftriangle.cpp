#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    void maxheight(int s, int n, int& height) {
        //cout << s << " : " << n << " : " << height << endl;
        if (height % 2) {
            s -= height;
            if (s < 0) {
                --height;
                return;
            }
        } else {
            n -= height;
            if (n < 0) {
                --height;
                return;
            }
        }

        height++;
        maxheight(s, n, height);
    }

public:
    int maxHeightOfTriangle(int red, int blue) {
        int rheight = 1;
        maxheight(red, blue, rheight);
        //cout << "**" << rheight << endl;
        int bheight = 1;
        maxheight(blue, red, bheight);
        //cout << "**" << bheight << endl;

        return bheight > rheight ? bheight : rheight;
        
    }
};

int main() {
    Solution s;
    
    cout << s.maxHeightOfTriangle(2, 4) << endl;
    cout << s.maxHeightOfTriangle(3, 3) << endl;
    cout << s.maxHeightOfTriangle(2, 1) << endl;
    cout << s.maxHeightOfTriangle(1, 1) << endl;
    cout << s.maxHeightOfTriangle(10, 1) << endl;

    return 0;
}