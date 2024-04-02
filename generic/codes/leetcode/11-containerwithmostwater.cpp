#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct _heightPos
{
    _heightPos(int p, int h) : pos(p), height(h) {}
    int pos;
    int height;
}heightPos;

class Solution {
public:
    // Start from left far to right far, and move to inwards based on which is smaller, as hiegher height will always
    // give the bigger value.
    int maxArea(vector<int>& height) {
        int result = 0, lenh = height.size();
        int st = 0, se = lenh - 1;
        while(st < se)
        {
            int lresult = min(height[st], height[se]) * (se - st);
            result = result > lresult ? result : lresult;
            if (height[se] < height[st])
                se--;
            else
                st++;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int tar[] = {1,8,6,2,5,4,8,3,7};
        vector<int> heights(tar, tar+9);
        cout << ob.maxArea(heights) << endl;
    }
    {
        int tar[] = {1,1};
        vector<int> heights(tar, tar+2);
        cout << ob.maxArea(heights) << endl;
    }
    {
        int tar[] = {2,2,2,6,2,2};
        vector<int> heights(tar, tar+6);
        cout << ob.maxArea(heights) << endl;
    }
    return 0;
}