#include <iostream>
#include <vector>

using namespace std;

// Idea is to know at each point, what's the min of (left max and right max), as more then that water can't be stored, rest all will get
// spilled, and once found the min, susbtract the current height, don't need to bother about continuation, it's more like just know what's
// possible at the current position.

class Solution {
public:
    // Solving using two pointers, which works, as we need to just find out min, and the movement of the pointer is based on whichever is smaller.
    // of left or right. 
    int trap(vector<int>& height) {
        int lh = height.size();
        vector<int> lmax(lh,0);
        vector<int> rmax(lh,0);
        int i = 1;
        for( ;i<lh-1; ++i)
        {
            lmax[i] = (lmax[i-1] > height[i-1]) ? lmax[i - 1] : height[i - 1];
            rmax[lh - i - 1] = (rmax[lh-i] > height[lh - i]) ? rmax[lh - i] : height[lh - i]; 
        }
        int result = 0;
        for(i=0; i<lh; ++i)
        {
            int water = (min(lmax[i], rmax[i])) - height[i];
            if (water < 0)
                water = 0;
            result += water;
        }

        return result;
    }
};

int main()
{
    Solution ob;
    {
        int tar[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        vector<int> heights(tar, tar+12);
        
        cout << ob.trap(heights) << endl;
    }
    {
        int tar[] = {4,2,0,3,2,5};
        vector<int> heights(tar, tar+6);
        
        cout << ob.trap(heights) << endl;
    }

    return 0;
}