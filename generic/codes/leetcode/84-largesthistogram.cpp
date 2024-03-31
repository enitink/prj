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
    int largestRectangleArea(vector<int>& heights) {
        int result = 0, i, lenh = heights.size();
        stack<heightPos> hst;
        hst.push(heightPos(0, heights[0]));
        for(i=1 ;i<lenh; ++i)
        {
            if (hst.top().height <= heights[i])
                hst.push(heightPos(i, heights[i]));
            else
            {
                int lastpos = -1;
                while(hst.empty() == false)
                {
                    heightPos hp = hst.top();
                    if (hp.height <= heights[i])
                        break;
                    hst.pop();
                    lastpos = hp.pos;
                    int lmax = (i - hp.pos) * hp.height;
                    result = (result > lmax) ? result : lmax;
                }
                hst.push(heightPos(lastpos, heights[i]));
            }
        }
        if (hst.empty() == false)
        {
            while(hst.empty() == false)
            {
                heightPos hp = hst.top();
                hst.pop();
                int lmax = (lenh - hp.pos) * hp.height;
                result = (result > lmax) ? result : lmax;
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int tar[] = {2,1,5,6,2,3};
        vector<int> heights(tar, tar+6);
        cout << ob.largestRectangleArea(heights) << endl;
    }
    {
        int tar[] = {2,4};
        vector<int> heights(tar, tar+2);
        cout << ob.largestRectangleArea(heights) << endl;
    }
    {
        int tar[] = {2,2,2,6,2,2};
        vector<int> heights(tar, tar+6);
        cout << ob.largestRectangleArea(heights) << endl;
    }
    return 0;
}